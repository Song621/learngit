#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {};
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

// 二叉树的序列化和反序列化 Leetcode 297
// 采用先序遍历的方式
string serialize(TreeNode* root){
    if(root == NULL){
        return "#_";
    }

    string result = root->val + "_";
    result += serialize(root->left);
    result += serialize(root->right);
    return result;
}

TreeNode* reconPreOrder(queue<string>* que){
    string val = que->front();
    que->pop();
    if(val.compare("#")){
        return NULL;
    }
    // stringstream ss(val);
    // int nodeVal;
    // ss << val;
    // ss >> nodeVal;
    // TreeNode* head = new TreeNode(nodeVal);
    TreeNode* head = new TreeNode(stoi(val));
    head->left = reconPreOrder(que);
    head->right = reconPreOrder(que);

    return head;
}

TreeNode* deserialize(string data) {
    queue<string> processed_data;
    stringstream ss(data);
    while(!ss.eof()){
        string nodeVal;
        getline(ss, nodeVal, '_');
        processed_data.push(nodeVal);
    }

    return reconPreOrder(&processed_data);
}