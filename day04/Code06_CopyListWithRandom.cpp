#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* rand;
    Node(int x): value(x) {}
};


Node* CopyListwithRandom(Node* head){
    unordered_map<Node*, Node*> map;
    Node* ptr = head;

    while(ptr != NULL){
        Node* copy = new Node(ptr->value);
        pair<Node*, Node*> item (ptr, copy);
        map.insert(item);
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != NULL){
        map[ptr]->next = ptr->next;
        map[ptr]->rand = ptr->rand;
        ptr = ptr->next;
    }

    return map[head];
}

int main(){
    cout<<"Copy List with Random:"<<endl;
    Node* head = new Node(1);
    Node* temp1 = new Node(2);
    Node* temp2 = new Node(3);

    head->next = temp1;
    head->rand = temp2;

    temp1->next = temp2;
    temp1->rand = head;

    temp2->next = NULL;
    temp2->rand = NULL;

    Node* copyhead = CopyListwithRandom(head);

    Node* ptr = copyhead;

    while(ptr != NULL){
        cout<<ptr->value<<endl;
        ptr = ptr->next;
    }
    return 0;
}
