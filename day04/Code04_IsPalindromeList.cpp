#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node(): value(0), next(NULL) {}
    Node(int x): value(x), next(NULL) {}
    Node(int x, Node* next): value(x), next(next) {}
};

bool IsPalindromeList(Node* head){
    stack<Node*> s;
    Node* ptr = head;

    while(ptr != NULL){
        s.push(ptr);
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != NULL){
        if(s.top()->value != ptr->value) return false;
        s.pop();
        ptr = ptr->next;
    }

    return true;
}

bool IsPalindromeList2(Node* head){
    // 快慢指针
    stack<Node*> s;
    Node* fast = head;
    Node* slow = head;
    Node* ptr = head;

    while(fast != NULL){
        // 针对为偶数个的情况
        if(fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        else{
            fast = fast->next;
        }
    }

    ptr = slow;
    while(ptr != NULL){
        s.push(ptr);
        ptr = ptr->next;
    }

    ptr = head;
    while(ptr != slow){
        if(s.top()->value != ptr->value) return false;
        s.pop();
        ptr = ptr->next;
    }

    return true;
}

Node* reverseLinkedList(Node* head){
    Node* pre = NULL;
    Node* ptr = head;

    while(ptr != NULL){
        ptr = ptr->next;
        head->next = pre;
        pre = head;
        head = ptr;        
    }

    return pre;
}

bool IspalindromeList3(Node* head){
    // 额外空间为1
    Node* fast = head;
    Node* slow = head;
    
    while(fast != NULL){
        if(fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        else{
            fast = fast->next;
        }
    }

    Node * ptr = head;
    Node* ptr_mid = slow;
    Node* ptr_end_head = reverseLinkedList(slow);

    while(ptr != NULL && ptr_end_head != NULL){
        if(ptr->value != ptr_end_head->value){
            return false;
        }
        ptr = ptr->next;
        ptr_end_head = ptr_end_head->next;
    }

    return true;

}

int main(){
    cout << "Is Palindrome List: " << endl;\
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    // head->next->next->next = new Node(1);

    bool a = IsPalindromeList2(head);
    cout << a << endl;
    return 0;
}