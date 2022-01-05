#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(NULL), right(NULL) {};
    TreeNode(int x): value(x), left(NULL), right(NULL) {};
};

struct ReturnType{
    bool isBalanced;
    int height;

    ReturnType(bool isB, int hei): isBalanced(isB), height(hei) {};
};
// 平衡二叉树，一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
// LeetCode 110
ReturnType process(TreeNode* node){
    if(node == NULL) return ReturnType(true, 0);

    // 向左右子树要信息：左子树是否为平衡二叉树，左子树的高度；右子树是否为平衡二叉树，右子树的高度
    // 递归套路
    ReturnType leftData = process(node->left);
    ReturnType rightData = process(node->right);

    // 当前树是平衡二叉树的条件：
    // 1). 左子树是平衡二叉树
    // 2). 右子树是平衡二叉树
    // 3). |左子树高度-右子树高度| <= 1
    int height = max(leftData.height+1, rightData.height+1);
    bool isBalanced = leftData.isBalanced && rightData.isBalanced && (abs(leftData.height - rightData.height) <= 1);

    return ReturnType(isBalanced, height);

    // if(!leftData.isBalanced || !rightData.isBalanced) return ReturnType(false, max(leftData.height, rightData.height));
    // else if(abs(leftData.height - rightData.height) <= 1){
    //     return ReturnType(true, max(leftData.height, rightData.height));
    // }
    // else{
    //     return ReturnType(false, max(leftData.height, rightData.height));
    // }
}

bool isBalanced(TreeNode* root){
    return process(root).isBalanced;
}