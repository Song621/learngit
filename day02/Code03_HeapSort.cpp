#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Heapfy(vector<int>& arr, int index, int heapsize){
    int left = 2*index + 1; //左孩子下标
    while(left<heapsize){ //下方还有孩子的时候
        // 两个孩子中，谁的值大，把下标给largest
        int largest = left + 1 < heapsize && arr[left] < arr[left+1] ? left + 1 : left;
        // 父和孩子之间，谁的值大，就把下标给largest
        largest = arr[largest] > arr[index] ? largest : index;
        if(largest == index){
            break;
        }
        
        swap(arr[index], arr[largest]);
        index = largest;
        left = 2*index - 1;
    }
}

void HeapInsert(vector<int>& arr, int index){
    //while条件有两层含义：孩子比父亲的值大， index=0时，(index-1)/2=0
    while(arr[index] > arr[(index-1)/2]){
        swap(arr[index], arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

void HeapSort(vector<int>& unsorted){
    //使整体变为大根堆
    //方法一：
    for(int i=0; i<unsorted.size(); i++){
        HeapInsert(unsorted, i);
    }
    //方法二：
    // for(int i=unsorted.size()-1; i>=0; i--){
    //     Heapfy(unsorted, i, unsorted.size());
    // }

    int heapsize = unsorted.size();
    //最大值和最后位置的值交换
    for(int i=0; i<unsorted.size()-1; i++){
        swap(unsorted[0], unsorted[--heapsize]);
        cout<<"unsorted[heapsize]: "<<unsorted[heapsize]<<endl;
        // heapsize--; 
        Heapfy(unsorted, 0, heapsize);
    }
    // swap(unsorted[0], unsorted[--heapsize]);
    // while(heapsize>0){
    //     swap(unsorted[0], unsorted[heapsize]);
    //     Heapfy(unsorted, 0, --heapsize);
    //     // heapsize--;
    // }
}

int main1(){
    cout<<"Heap Sort: "<<endl;
    // int a = 0;
    // cout<<"(a-1)/2: "<< (a-1)/2 <<endl;
    vector<int> unsorted_seq;
    unsorted_seq.push_back(12);
    unsorted_seq.push_back(1);
    unsorted_seq.push_back(13);
    unsorted_seq.push_back(4);
    unsorted_seq.push_back(54);
    unsorted_seq.push_back(6);
    unsorted_seq.push_back(23);
    unsorted_seq.push_back(99);
    unsorted_seq.push_back(8);

    int a = unsorted_seq.size();
    cout<<"unsorted_seq[end]: "<< unsorted_seq[a]<<endl;
    cout<<"unsorted_seq[--end]: "<< unsorted_seq[--a]<<endl;
    cout<<"a: "<<a<<endl;

    HeapSort(unsorted_seq);
    for(int i=0; i<unsorted_seq.size(); i++){
        cout<<unsorted_seq[i]<<endl;
    }
    return 0;
}

int main(){
    //对于基础类型 默认是大顶堆
    priority_queue<int> q;
    // priority_queue<int, vector<int>, greater<int> > q;
    // for (int i = 0; i < 5; i++) 
    // {
    //     q.push(i);
    // }

    q.push(2);
    q.push(8);
    q.push(1);
    q.push(6);  
    q.push(12);
    q.push(3);

    while(!q.empty()){
        cout << q.top() <<endl;  
        q.pop();      
    }

    return 0;
}