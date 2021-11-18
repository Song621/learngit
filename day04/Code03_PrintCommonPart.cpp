#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int value;
    Node* next;
    Node(): value(0), next(NULL) {}
    Node(int x): value(x), next(NULL) {}
    Node(int x, Node* next): value(x), next(next) {}
};

void printCommenPart(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->value < ptr2->value){
            ptr1 = ptr1->next;
        }
        else if(ptr1->value > ptr2->value){
            ptr2 = ptr2->next;
        }
        else{
            cout << ptr1->value << endl;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

}

int main(){
    cout<<"Print Commen Part: "<<endl;
    Node* node1 = new Node(2);
    node1->next = new Node(3);
    node1->next->next = new Node(5);
    node1->next->next->next = new Node(6);

    Node* node2 = new Node(1);
    node2->next = new Node(2);
    node2->next->next = new Node(5);
    node2->next->next->next = new Node(7);
    node2->next->next->next->next = new Node(8);

    printCommenPart(node1, node2);
    return 0;
}