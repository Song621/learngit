#include <iostream>
#include <set>
// #include <tr1/unordered_map>

using namespace std;
// using namespace std::tr1;

struct Node{
    int value;
    Node* next;
    Node(int x): value(x), next(NULL) {};
    Node(int x, Node* next): value(x), next(next) {};
};

Node* getLoopNode(Node* head){
    
}

Node* FindFirstIntersectNode(Node* head){
    set<Node*> s;
    Node* ptr = head;

    while(ptr != NULL){
        if(s.count(ptr) == 0) s.insert(ptr);
        else{
            return ptr;
        }
        ptr = ptr->next;
    } 
}

Node* FindFirstIntersectNode1(Node* head){
    if(head == NULL || head->next ==NULL || head->next->next == NULL){
        return NULL;
    }
    Node* fast = head->next->next;
    Node* slow = head->next;

    while(fast != slow){
        if(fast->next == NULL || fast->next->next == NULL){
            return NULL;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}



int main(){
    cout<<"Find First Intersect Node: "<<endl;
    Node* head = new Node(1);
    Node* x1 = new Node(2);
    Node* x2 = new Node(3);
    Node* x3 = new Node(4);
    Node* x4 = new Node(5);

    head->next = x1;
    x1->next = x2;
    x2->next = x3;
    x3->next = x4;
    x4->next = x2;

    Node* ptr = FindFirstIntersectNode1(head);
    cout<<"The First Intersect Node is: "<<ptr->value<<endl;
    return 0;
}