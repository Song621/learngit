#include <iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

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

Node* CopyListwithRandom2(Node* head){
    Node* ptr = head;

    while(ptr != NULL){
        Node* copyNode = new Node(ptr->value);
        copyNode->next = ptr->next;
        ptr->next = copyNode;
        ptr = copyNode->next;
    }

    // ptr = head;
    // while(ptr != NULL){
    //     ptr->next->rand = ptr->rand->next;
    //     ptr = ptr->next->next;
    // }

    ptr = head;
    Node* ptr1 = head->next;
    while(ptr != NULL){
        // cout<<"ptr->rand->value: "<<ptr->rand->value<<endl;
        if(ptr->rand != NULL){
            ptr1->rand = ptr->rand->next;
        }
        else{
            ptr1->rand = NULL;
        }
        ptr = ptr1->next;
        // cout<<"ptr->value: "<<ptr->value<<endl;
        if(ptr != NULL) ptr1 = ptr->next;
    }  
    
    ptr = head;
    ptr1 = head->next;
    while(ptr != NULL){
        ptr = ptr1->next;
        if(ptr == NULL) break;
        ptr1->next = ptr->next;
        ptr1 = ptr1->next;
    }

    return head->next;
    // return head;
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

    // Node* copyhead = CopyListwithRandom(head);
    Node* copyhead = CopyListwithRandom2(head);
    // unordered_map<Node*, Node*> map;
    // Node* ptr = head;

    // while(ptr != NULL){
    //     Node* copy = new Node(ptr->value);
    //     pair<Node*, Node*> item (ptr, copy);
    //     map.insert(item);
    //     ptr = ptr->next;
    // }

    Node* ptr = copyhead;
    // Node* ptr = head;
    // ptr = head;
    while(ptr != NULL){
        cout<<ptr->value<<endl;
        ptr = ptr->next;
    }
    return 0;
}
