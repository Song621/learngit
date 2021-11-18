#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node* next;
    // 构造函数
    Node() : value(0), next(NULL) {}
    Node(int x) : value(x), next(NULL) {}
    Node(int x, Node* next) : value(x), next(next) {}
};

Node* deleteValueNode(Node* head, int val){
    Node* start = new Node(-1, head);
    Node* ptr = start;

    while(ptr != NULL && ptr->next != NULL){
        if(ptr->next->value == val){
            Node* ptr2 = ptr->next;
            ptr->next  =ptr2->next;
            ptr = ptr->next;
            delete ptr2;
            continue;
        }
        ptr = ptr->next;
    }
    return start->next;
}

Node* reverseLinkedList(Node* head){
    Node* pre = NULL;
    Node* ptr = head;

    // pre, head, ptr分别指向上一个，当前，下一个
    // 最终pre指向最后一个节点
    while(ptr != NULL){
        //ptr遍历节点，先把ptr移到下一个，即保存下一个节点的地址
        ptr = ptr->next;
        //当前节点的next指针指向上一个
        head->next = pre;
        //原本指向上一个的pre后移
        pre = head;
        //当前节点指针后移一个
        head = ptr;
    }
    return pre;
}


struct DLNode{
    int value;
    DLNode* next;
    DLNode* back;
    DLNode(): value(0), next(NULL), back(NULL) {}
    DLNode(int x): value(x), next(NULL), back(NULL) {}
    DLNode(int x, DLNode* next, DLNode* back): value(x), next(next), back(back) {}
};


DLNode* reverseDoubleLinkedList(DLNode* head){
    DLNode* pre = NULL;
    DLNode* ptr = head;

    while(ptr != NULL){
        ptr = ptr->next;
        head->next = pre;
        head->back = ptr;
        pre = head;
        head = ptr;
    }
    return pre;
}

int main(){
    cout<<"Reverse LinkedList: "<<endl;
    int a[6] = {1,2,3,4,5,6};
    DLNode* head = new DLNode(a[0]);
    DLNode* ptr = head;

    for(int i=1; i<6; i++){
        DLNode* NewNode = new DLNode(a[i]);
        ptr->next = NewNode;
        NewNode->back = ptr;
        ptr = NewNode;
    }
    ptr->next = NULL;
    ptr = head;
    DLNode* end = NULL;
    while(ptr != NULL){
        cout<<ptr->value<<endl;
        end = ptr;
        ptr = ptr->next;
    }
    ptr = end;
    while(ptr != NULL){
        cout<<ptr->value<<endl;
        ptr = ptr->back;
    }

    cout<<"Reversed: "<<endl;
    
    ptr = reverseDoubleLinkedList(head);
    while(ptr != NULL){
        cout<<ptr->value<<endl;
        ptr = ptr->next;
    }

    return 0;
}
