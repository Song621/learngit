#include <iostream>
#include <vector>
#include <queue>
// #include <math.h>
using namespace std;

void SortArrayDistanceLess_A(vector<int>& unsorted, int k){
    priority_queue<int> q;
    int index = 0;
    int l = unsorted.size();
    for(; index < min(l, index); index++){
        q.push(unsorted[index]);
    }
    int i=0;
    for(; index<l; index++, i++){
        q.push(unsorted[index]);
        unsorted[i] = q.top();
        q.pop();
    }
    while(!q.empty()){
        unsorted[i++] = q.top();
        q.pop();
    }
}

void SortArrayDistanceLess(vector<int>& unsorted, int k){
    priority_queue<int> q;
    vector<int> temp(unsorted.size());
    for(int i=0; i<=k; i++){
        q.push(unsorted[i]);
    }
    temp[0] = q.top();
    q.pop();

    for(int i=k+1; i<unsorted.size(); i++){
        q.push(unsorted[i]);
        temp[i-k] = q.top();
        q.pop();
    }

    for(int j=unsorted.size()-k; j<unsorted.size(); j++){
        temp[j] =  q.top();
        q.pop();
    }
    for(int j=0; j<unsorted.size(); j++){
        unsorted[j] = temp[j];
    }
    
}

int main(){
    cout<<"Sort Array Distance Less"<<endl;
    vector<int> a(10);
    int l = a.size();
    cout<<min(1, l)<<endl;
    return 0;
}