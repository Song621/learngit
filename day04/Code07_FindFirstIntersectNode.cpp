#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int x): value(x) {};
    Node(int x, Node* next): value(x), next(next) {};
};

Node* FindFirstIntersectNode(Node* head){

}

int main(){
    cout<<"Find First Intersect Node: "<<endl;

    return 0;
}