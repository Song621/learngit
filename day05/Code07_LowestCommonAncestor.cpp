#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 最低公共祖先节点LCA LeetCode 236
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    // 发现目标节点或者遍历到了叶子节点，返回
    if(root == NULL || root == p || root == q){
        return root;
    }

    // 向左右子树要信息
    TreeNode* left = LowestCommonAncestor(root->left, p, q);
    TreeNode* right = LowestCommonAncestor(root->right, p, q);

    // 左右子树均包含目标节点，那么当前节点是最低公共节点,返回当前节点
    //          x
    //         / \
    //        O   q
    //       / 
    //      p   
    if(left != NULL && right != NULL){
        return root;
    }

    // 只有一侧子树找见了目标，说明应一个目标在当前目标的下面，返回发现的目标节点 Leecoe
    //          O
    //         / \
    //        p   O
    //       / \ 
    //      O   q
    return left != NULL ? left : right;
}