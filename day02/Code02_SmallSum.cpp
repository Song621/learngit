#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& unsorted, int L, int M, int R){
    int p1 = L;
    int p2 = M + 1;
    int i = 0;
    int sum = 0;
    vector<int> temp(R-L+1);

    while(p1<=M && p2<=R){
        sum += unsorted[p1] < unsorted[p2] ? (R-p2+1)*unsorted[p1] : 0;
        temp[i++] = unsorted[p1] < unsorted[p2] ? unsorted[p1++] : unsorted[p2++];     
    }

    while(p1<=M){
        temp[i++] = unsorted[p1++];
    }

    while(p2<=R){
        temp[i++] = unsorted[p2++];
    }

    for(int j = 0; j<temp.size(); j++){
        unsorted[L+j] = temp[j];
    }
    
    return sum;
}

// arr[L...R]既要排好序，也要求小和
int MergeSort(vector<int>& unsorted, int L, int R){
    if(L == R) return 0;

    int M = int(L + (R-L) / 2);
    int a = MergeSort(unsorted, L, M);
    int b = MergeSort(unsorted, M+1, R);
    int c = merge(unsorted, L, M, R);
    return a + b + c;
}


int SmallSum(vector<int>& unsorted){
    return MergeSort(unsorted, 0, unsorted.size()-1);
}

int main(){
    cout << "Small Num:" << endl;
    vector<int> unsorted_seq;
    unsorted_seq.push_back(1);
    unsorted_seq.push_back(3);
    unsorted_seq.push_back(4);
    unsorted_seq.push_back(2);
    unsorted_seq.push_back(5);

    cout<<SmallSum(unsorted_seq)<<endl;
    return 0;
}