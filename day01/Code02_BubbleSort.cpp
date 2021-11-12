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
    int a[10]= {1,1,2,2,2,3,3,4,4,4};
    // a[0] = 1;
    // a[1] = 1;
    // a[2] = 2;
    // a[3] = 2;
    // a[4] = 2;

    // a[5] = 3;
    // a[6] = 3;
    // a[7] = 4;
    // a[8] = 4;
    // a[9] = 4;

    int eor = 0;
    for(int i=0; i<10; i++){
        eor ^= a[i];
    }

    int rightOne = eor & (~eor + 1);
    int onlyone = 0;
    for(int i=0; i<10; i++){
        if((rightOne & a[i]) == 0) onlyone ^= a[i]; //注意括号(rightOne & a[i]) ==优先级好似高于&，也可以(rightOne & a[i]) == rightOne
    }

    // int answer1 = eor ^ onlyone;
    int answer1 = eor ^ onlyone;

    cout<<"answer1: "<< onlyone<<endl;
    cout<<"answer2: "<< answer1<<endl;
    return 0;
}

int main1(){
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