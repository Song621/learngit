#include <iostream>
#include <vector>

using namespace std;

int resort(vector<int>& unsorted, int L, int R, int num){
    int p1 = -1 + L;
    for(int i=L; i<=R; i++){
        if(unsorted[i] <= num){
            swap(unsorted[i], unsorted[p1+1]);
            p1++;
        }
    }
    return p1;
}

// void QuickSort_V1B(vector<int>& unsorted, int L, int R){
//     if(L == R) return;
//     int partition = resort(unsorted, L, R-1, unsorted[R]);
//     // swap(unsorted[partition+1], unsorted[R]);

//     两种特殊情况，全小于或全大于
//     if(partition == L-1){
//         swap(unsorted[partition+1], unsorted[R]);
//         QuickSort_V1(unsorted, partition+2, R);
//     }
//     else if(partition == R-1){
//         // swap(unsorted[partition+1], unsorted[R]);
//         QuickSort_V1(unsorted, L, partition);
//     }
//     else{
//         swap(unsorted[partition+1], unsorted[R]);
//         QuickSort_V1(unsorted, L, partition);
//         QuickSort_V1(unsorted, partition+2, R);
//     }
// }

// (L<R的条件很巧妙，避免了上面处理特殊情况的代码)
void QuickSort_V1(vector<int>& unsorted, int L, int R){
    if(L < R){
        int partition = resort(unsorted, L, R-1, unsorted[R]);
        swap(unsorted[partition+1], unsorted[R]);
        QuickSort_V1(unsorted, L, partition);
        QuickSort_V1(unsorted, partition+2, R);
    }
}

int main(){
    cout<<"Quick Sort"<<endl;
    vector<int> unsorted_seq;
    // unsorted_seq.push_back(1);
    // unsorted_seq.push_back(12);
    // unsorted_seq.push_back(3);
    // unsorted_seq.push_back(14);
    // unsorted_seq.push_back(54);
    // unsorted_seq.push_back(6);

    unsorted_seq.push_back(12);
    unsorted_seq.push_back(1);
    unsorted_seq.push_back(13);
    unsorted_seq.push_back(4);
    unsorted_seq.push_back(54);
    unsorted_seq.push_back(6);
    unsorted_seq.push_back(23);
    unsorted_seq.push_back(99);
    unsorted_seq.push_back(8);

    // resort(unsorted_seq, 20);
    // QuickSort_V1(unsorted_seq, 0, unsorted_seq.size()-1);
    QuickSort_V1(unsorted_seq, 0, unsorted_seq.size()-1);
    // int t = resort(unsorted_seq, 0, unsorted_seq.size()-1, 0);
    // cout<<"partition p: "<<t<<endl;
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<<unsorted_seq[i]<<endl;
    }
    
    return 0;
}