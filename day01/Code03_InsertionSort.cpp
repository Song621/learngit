#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& unsorted){
    for(int i=1; i<unsorted.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(unsorted[j] > unsorted[j+1]) swap(unsorted[j], unsorted[j+1]);
        }
    }
}


int main(){
    cout<<"Insertion Sort: "<<endl;
    vector<int> unsorted_seq;
    unsorted_seq.push_back(12);
    unsorted_seq.push_back(1);
    unsorted_seq.push_back(32);
    unsorted_seq.push_back(4);
    unsorted_seq.push_back(54);
    unsorted_seq.push_back(6);
    unsorted_seq.push_back(23);
    unsorted_seq.push_back(99);
    unsorted_seq.push_back(8);

    InsertionSort(unsorted_seq);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<< unsorted_seq[i]<<endl;
    }
    return 0;
}