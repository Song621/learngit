#include <iostream>
#include <vector>
using namespace std;

void SelectionSort(vector<int>& unsorted){
    if(unsorted.empty()) return;

    for(int i=0; i<unsorted.size()-1; i++){
        int min = i;
        for(int j=i+1; j<unsorted.size(); j++){
            // if(unsorted[j]<unsorted[min]) min = j; 
            min = unsorted[j]<unsorted[min] ? j : min;
        }
        int temp = unsorted[i];
        unsorted[i] = unsorted[min];
        unsorted[min] = temp;
    }
}

int main1(){
    cout<<"hello"<<endl;
    return 0;
}
int main(){
    cout<<"hello"<<endl;
    vector<int> unsorted_seq;
    unsorted_seq.push_back(33);
    unsorted_seq.push_back(12);
    unsorted_seq.push_back(45);
    unsorted_seq.push_back(1);
    unsorted_seq.push_back(99);
    unsorted_seq.push_back(10);

    SelectionSort(unsorted_seq);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout <<unsorted_seq[i]<< endl;
    }
    return 0;
}
class