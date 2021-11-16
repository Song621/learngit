#include <iostream>
#include <vector>
#include <cmath>
// #define INT_MIN 0x80000000;
using namespace std;


int maxbits(vector<int>& unsorted){
    int max_value=INT_MIN;
    for(int i=0; i<unsorted.size(); i++){
        max_value = max(max_value, unsorted[i]);
    }
    int res=0;
    while(max_value!=0){
        res++;
        max_value /= 10;
    }
    return res;
}

int getDigit(int x, int d){
    return ((x / ((int) pow(10, d - 1))) % 10);
}

void radixSort(vector<int>& unsorted, int begin, int end, int digit){
    int radix = 10;
    
    vector<int> bucket(end-begin+1);
    for(int d=1; d<=digit; d++){
        vector<int> count(radix);
        int j=0;
        for(int i=begin; i<=end; i++){
            j = getDigit(unsorted[i], d);
            count[j]++;
        }
        for(int i=1; i<radix; i++){
            count[i] = count[i] + count[i-1];
        }
        for(int i=end; i>=begin; i--){
            j = getDigit(unsorted[i], d);
            bucket[count[j]-1] = unsorted[i];
            count[j]--;
        }
        for(int i=begin; i<=end; i++){
            unsorted[i] = bucket[i];
        }
    }
}

void RadixSort(vector<int>& unsorted){
    if(unsorted.empty() || unsorted.size() < 2){
        return;
    }
    radixSort(unsorted, 0, unsorted.size()-1, maxbits(unsorted));
}



int main(){
    cout<<"Radix Sort: "<<endl;
    // cout<<getDigit(12,1)<<endl;
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

    RadixSort(unsorted_seq);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<< unsorted_seq[i] << endl;
    }

    return 0;
}