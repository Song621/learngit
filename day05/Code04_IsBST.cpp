#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(NULL), right(NULL) {};
    TreeNode(int x): value(x), left(NULL), right(NULL) {};
};

// LeetCode 98
bool isBST(TreeNode* root){
    stack<TreeNode*> traversal;
    int preValue = -10;

    while(!traversal.empty() || root != NULL){
        if(root != NULL){
            traversal.push(root);
            root = root->left;
        }
        else{
            TreeNode* temp = traversal.top();
            traversal.pop();
            if(temp->value <= preValue){
                return false;
            }
            else{
                preValue = temp->value;
            }
            root = temp->right;
        }
    }
    return true;
}

// 按照二叉树的递归套路
struct ReturnType{
    bool isBinarySearch;
    int min_t;
    int max_t;
    ReturnType(bool isBS, int mi, int ma): isBinarySearch(isBS), min_t(mi), max_t(ma) {};
};

ReturnType process(TreeNode* node){
    if(node == NULL) return ReturnType(true, INT_MIN, INT_MAX);

    ReturnType leftData = process(node->left);
    ReturnType rightData = process(node->right);

    int min_t = min(leftData.min_t, rightData.min_t);
    int max_t = max(leftData.max_t, rightData.max_t);
    bool isBinarySearch = leftData.isBinarySearch && rightData.isBinarySearch &&
                        (node->value > leftData.max_t) && (node->value < rightData.min_t);
    return ReturnType(isBinarySearch, min_t, max_t);
}

// 返回结构体指针
ReturnType *process1(TreeNode* node){
    // if(node == NULL) return ReturnType(true, INT_MAX, INT_MIN);
    if(node == NULL) return NULL;

    // 向左右子树要信息：左子树是否为二叉搜索树，左子树的max；右子树是否为二叉搜索树，右子树的min
    // 要使用递归，统一返回的信息
    ReturnType* leftData = process1(node->left);
    ReturnType* rightData = process1(node->right);
    
    int min_t = node->value;
    int max_t = node->value;
    if(leftData != NULL){
        min_t = min(min_t, leftData->min_t);
        max_t = max(max_t, leftData->max_t);
    }
    if(rightData != NULL){
        min_t = min(min_t, rightData->min_t);
        max_t = max(max_t, rightData->max_t);
    }

    // 当前树是二叉搜索树的条件：
    // 1). 左树是二叉搜索树
    // 2). 右树是二叉搜索树 
    // 3). 左树max < x < 右树min 
    bool isBST = true;
    if(leftData != NULL && (!leftData->isBinarySearch || leftData->max_t >= node->value)){
        isBST = false;
    }
    if(rightData != NULL && (!rightData->isBinarySearch || rightData->min_t <= node->value)){
        isBST = false;
    }

    return new ReturnType(isBST, min_t, max_t);
}

bool isBST1(TreeNode* root){
    return process(root).isBinarySearch;
}
int main(){
    // cout << "Is BST: " << INT_MIN << " -----" << INT_MIN-1 << endl;
    cout << "Is BST: " << endl;
    return 0;
}