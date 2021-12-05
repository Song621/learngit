#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(NULL), right(NULL) {};
    TreeNode(int x): value(x), left(NULL), right(NULL) {};
};

void BFS(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> traversal;
    traversal.push(root);
    
}

int main(){
    cout << "BFS: " << endl;

    return 0;
}