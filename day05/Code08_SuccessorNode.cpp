#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 后继结点问题 LeetCode 后继者
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    // 中序遍历
    vector<TreeNode*> result; // 存储中序遍历结果
    stack<TreeNode*> traversal;

    while(!traversal.empty() || root != NULL){
        if(root != NULL){
            traversal.push(root);
            root = root->left;
        }
        else{
            root = traversal.top();
            traversal.pop();
            result.push_back(root);
            root = root->right;
        }
    }

    // 在中序遍历结果中查找后继节点
    for(int i=0; i<result.size()-1; i++){
        if(result[i] == p){
            return result[i+1];
        }
    }

    return NULL;
}

// 对于二叉搜索树来说，中序遍历的结果是升序的
// 因此，查找p的过程，若p的值 < root的值，在左子树查找，p的值 > root的值，在右子树查找
// 若p的值 < root的值，后继节点一定在左子树或者当前节点就是后继节点
// 若p的值 > root的值，后继节点一定在右子树
// 自己写的，不太对
TreeNode* inorderSuccessorBST(TreeNode* root, TreeNode* p){
    if(root == p){
        return root;
    }

    TreeNode* findp;
    if(p->val < root->val){
        findp = inorderSuccessorBST(root->left, p);
    }
    else{ // 在右子树中查找目标节点p
        findp = inorderSuccessorBST(root->right, p);
    }

    if(findp->right != NULL){
        return findp->right;
    }

    return root->val > findp->val ? root : findp;
}

// 成功运行，对这个方法理解的不够透彻，可能是测试数据规模小的原因，效率与中序遍历得到遍历序的结果差距并不大。
TreeNode* inorderSuccessorBST(TreeNode* root, TreeNode* p){
    if(root == NULL){
        return NULL;
    }

    // 当前节点的值小于等于目标节点的值，那么当前目标值的后继者必然在右子树
    if(p->val >= root->val){
        return inorderSuccessorBST(root->right, p);
    }
    // 否则节点有可能是当前节点，或者在当前节点的左子树中
    // 那么可以先去左子树找一下试试，找不到的话返回当前节点即是结果
    TreeNode* node = inorderSuccessorBST(root->left, p);
    return node == NULL ? root : node;
}