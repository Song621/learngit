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

Node* SmallEqualBigger2(Node* head, int val){
    Node* SH = NULL;
    Node* ST = NULL;
    Node* EH = NULL;
    Node* ET = NULL;
    Node* BH = NULL;
    Node* BT = NULL;
    Node* ptr = head;

    while(ptr!=NULL){
        if(ptr->value < val){
            if(SH == NULL){
                SH = ptr;
                ST = ptr;
            }
            else{
                ST->next = ptr;
                ST = ptr;
            }
        }
        else if(ptr->value == val){
            if(EH == NULL){
                EH = ptr;
                ET = ptr;
            }
            else{
                EH->next = ptr;
                ET = ptr;
            }
        }
        else{
            if(BH == NULL){
                BH = ptr;
                BT = ptr;
            }
            else{
                BH->next = ptr;
                BT = ptr;
            }
        }
        ptr = ptr->next;
    }

    if(SH != NULL && EH != NULL && BH != NULL){
        ptr = SH;
        ST->next = EH;
        ET->next = BH;
        BT->next = NULL;
    }
    else if(SH != NULL && EH != NULL){
        ptr = SH;
        ST->next = EH;
        ET->next = NULL;
    }
    else if(SH != NULL && BH != NULL){
        ptr = SH;
        ST->next = BH;
        BT->next = NULL;
    }
    else if(EH != NULL && BH != NULL){
        ptr = EH;
        ET->next = BH;
        BT->next = NULL;
    }
    else if(SH != NULL){
        ptr = SH;
        ST->next = NULL;
    }
    else if(EH != NULL){
        ptr = EH;
        ET->next = NULL;
    }
    else if(BH != NULL){
        ptr = BH;
        BT->next = NULL;
    }
    else{
        return NULL;
    }

    return ptr;
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

    // ptr = SmallEqualBigger(head, 5);
    ptr = SmallEqualBigger2(head, 5);

    while(ptr != NULL){
        cout<< ptr->value <<endl;
        ptr = ptr->next;
    }
    return 0;
}