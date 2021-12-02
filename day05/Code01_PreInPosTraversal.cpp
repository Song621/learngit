#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(NULL), right(NULL) {};
    TreeNode(int x): value(x), left(NULL), right(NULL) {};
};

 vector<int> preorderTraversal(TreeNode* root){
     vector<int> result;
     stack<TreeNode*> traversal;
     traversal.push(root);

     if(root == NULL){
         return result;
     }

     while(!traversal.empty()){
         TreeNode* tempNode = traversal.top();
         traversal.pop();
         result.push_back(tempNode->value);

         if(tempNode->right != NULL){
             traversal.push(tempNode->right);
         }

         if(tempNode->left != NULL){
             traversal.push(tempNode->left);
         }
     }

     return result;
 }

vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> traversal;
    // traversal.push(root);

    if(root == NULL){
        return result;
    }

    while(!traversal.empty() || root != NULL){
        if(root != NULL){
            traversal.push(root);
            root = root->left;
        }
        else{
            root = traversal.top();
            traversal.pop();
            result.push_back(root->value);
            root = root->right;
            // traversal.push(root);
        }
        // while(traversal.top()->left != NULL){
        //     TreeNode* tempNode = traversal.top()->left;
        //     traversal.push(tempNode);
        // }
        // TreeNode* tempNode = traversal.top();
        // traversal.pop();
        // result.push_back(tempNode->value);
        // if(tempNode->right != NULL){
        //     traversal.push(tempNode->right);
        // }
        // if(tempNode->right == NULL){ //当前节点是叶节点，弹出当前节点及其父节点，压入父节点右孩子(如果有的话)
        //     traversal.pop();
        //     result.push_back(tempNode->value);
        //     tempNode = traversal.top();
        //     traversal.pop();
        //     result.push_back(tempNode->value);
        //     if(tempNode->right != NULL){
        //         traversal.push(tempNode->right);
        //     }

        // }
        // else{//当前节点无左孩子有右孩子，弹出当前节点，压入右孩子
        //     traversal.pop();
        //     result.push_back(tempNode->value);      
        //     traversal.push(tempNode->right);
        // }

    }

    return result;
}

vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> traversal;
    stack<TreeNode*> output;
    traversal.push(root);

    if(root == NULL){
        return result;
    }

    while(!traversal.empty()){
        TreeNode* tempNode = traversal.top();
        traversal.pop();
        output.push(tempNode);

        if(tempNode->left != NULL){
            traversal.push(tempNode->left);
        }
        if(tempNode->right != NULL){
            traversal.push(tempNode->right);
        }
    }

    while(!output.empty()){
        result.push_back(output.top()->value);
        output.pop();
    }

    return result;
}

int main(){
    cout<<"PreInPosTraversal: "<<endl;
    TreeNode* head = new TreeNode(1);
    TreeNode* head_left = new TreeNode(2);
    TreeNode* head_right = new TreeNode(3);
    TreeNode* left3_1 = new TreeNode(4);
    TreeNode* right3_1 = new TreeNode(5);
    TreeNode* left3_2 = new TreeNode(6);
    TreeNode* right3_2 = new TreeNode(7);

    head->left = head_left;
    head->right = head_right;
    head_left->left = left3_1;
    head_left->right = right3_1;
    head_right->left = left3_2;
    head_right->right = right3_2;

    vector<int> result;
    // result = preorderTraversal(head);
    // result = inorderTraversal(head);
    result = postorderTraversal(head);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}