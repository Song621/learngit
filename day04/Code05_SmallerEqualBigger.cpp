#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(): value(0), next(NULL) {};
    Node(int x): value(x), next(NULL) {};
    Node(int x, Node* next): value(x), next(next) {};
};


void partition(vector<Node*>& unsorted, int val){
    int smaller_index = -1;
    int bigger_index = unsorted.size();

    int i = 0;
    while(i<unsorted.size() && i+1 != bigger_index){
        if(unsorted[i]->value < val){
            swap(unsorted[i], unsorted[smaller_index+1]);
            smaller_index++;
            i++;
        }
        else if(unsorted[i]->value == val){
            i++;
        }
        else{
            swap(unsorted[i], unsorted[bigger_index-1]);
            bigger_index--;
        }
    }
}

Node* SmallEqualBigger(Node* head, int val){
    vector<Node*> l;
    Node* ptr = head;

    while(ptr != NULL){
        l.push_back(ptr);
        ptr = ptr->next;
    }

    partition(l, val);

    for(int i=0; i<l.size()-1; i++){
        l[i]->next = l[i+1];
    }
    l.back()->next = NULL;

    return l[0];
}

int main(){
    cout << "Small Equal Bigger" << endl;
    int value[7] = {4, 6, 3, 5, 8, 5, 2};
    Node* head = new Node(4);
    Node* ptr = head;
    for(int i=1; i<7; i++){
        ptr->next = new Node(value[i]);
        ptr = ptr->next;
    }
    ptr->next = NULL;

    ptr = SmallEqualBigger(head, 5);

    while(ptr != NULL){
        cout<< ptr->value <<endl;
        ptr = ptr->next;
    }
    return 0;
}