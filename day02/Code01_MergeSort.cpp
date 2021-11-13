#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& unsorted, int L, int M, int R){
    // 双指针
    int p1 = L;
    int p2 = M+1;
    int i = 0;
    vector<int> temp(R-L+1);
    // int temp[R-L+1];

    while(p1<=M && p2<=R){
        temp[i++] = unsorted[p1] <= unsorted[p2] ? unsorted[p1++] : unsorted[p2++];
    }

    // copy剩余的值，下面两个while只有一个满足条件
    while(p1<=M){
        temp[i++] = unsorted[p1++];
    }
    while(p2<=R){
        temp[i++] = unsorted[p2++];
    }

    for(int j=0; j< temp.size(); j++){
        unsorted[L+j] = temp[j];// 注意L+j
    }
    // failed test
    // for(int p1 = L; p1<=M; p1++){
    //     for(int j = p2; j<=R; j++){
    //         if(unsorted[p1]>unsorted[j]){
    //             swap(unsorted[p1], unsorted[j]);
    //             p2=j+1;
    //             break;
    //         }
    //     }
    // }
}
void MergeSort(vector<int>& unsorted, int L, int R){
    // 复杂度O(N*log(N))
    if(L == R) return;

    int M = int(L + (R - L) / 2);
    MergeSort(unsorted, L, M);
    MergeSort(unsorted, M+1, R);
    merge(unsorted, L, M, R);
}

int main(){
    cout<<"Merge Sort: "<<endl;
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
    cout<<"unsorted_seq.size: "<<unsorted_seq.size()<<endl;
    MergeSort(unsorted_seq, 0, unsorted_seq.size()-1);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<< unsorted_seq[i]<<endl;
    }
    return 0;
}