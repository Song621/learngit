#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int value;
    Node* next;
    // 构造函数
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(int x, Node* next) : value(x), next(next) {}
};

Node* deleteValueNode(Node* head, int val){
    Node* start = new Node(-1, head);
    Node* ptr = start;

    while(ptr != nullptr && ptr->next != nullptr){
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
    Node* pre = nullptr;
    Node* ptr = head;

    // pre, head, ptr分别指向上一个，当前，下一个
    // 最终pre指向最后一个节点
    while(ptr != nullptr){
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

int main(){
    cout<<"Reverse LinkedList: "<<endl;

    return 0;
}
