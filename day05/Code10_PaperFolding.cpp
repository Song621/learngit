#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 折纸问题
// 头节点为凹折痕
// 每一棵左子树的头节点都为凹
// 每一棵右子树的头节点都为凸
// 中序遍历，递归，空间复杂度O(N)
//         1凹
//        /   \
//      2凹   2凸
//     /  \   /  \
//   3凹 3凸 3凹 3凸
// 上|——————————————|下
void printProcess(int i, int N, bool down){
    if(i>N) return;

    printProcess(i+1, N, true);
    cout<< (down ? "down" : "up") << endl;
    printProcess(i+1, N, false);
}

void printAllFolds(int N){
    printProcess(1, N, true);
}

int main(){
    int N = 3;
    printAllFolds(N);

    return 0;
}