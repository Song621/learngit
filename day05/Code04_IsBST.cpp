#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(NULL), right(NULL) {};
    TreeNode(int x): value(x), left(NULL), right(NULL) {};
};

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

int main(){
    cout << "Is BST: " << INT_MIN << " -----" << INT_MIN-1 << endl;

    return 0;
}