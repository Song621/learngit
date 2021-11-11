#include <iostream>
#include <vector>

using namespace std;

void my_swap(vector<int>& unsorted, int i, int j){
    // 注意：i和j不能是同一位置
    unsorted[i] = unsorted[i] ^ unsorted[j];
    unsorted[j] = unsorted[i] ^ unsorted[j];
    unsorted[i] = unsorted[i] ^ unsorted[j];
}
void BubbleSort(vector<int>& unsorted){
    if(unsorted.empty()) return;
    for(int e=unsorted.size()-1; e>0; e--){
        for(int i=0; i<e; i++){
            if(unsorted[i]>unsorted[i+1]) swap(unsorted[i], unsorted[i+1]);
        }
    }
}

int main(){
    cout<<"hello"<<endl;
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
    cout<<"unsorted_seq.size() = "<<unsorted_seq.size()<<endl;
    BubbleSort(unsorted_seq);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<< unsorted_seq[i]<<endl;
    }
    return 0;
}