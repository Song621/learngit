#include <iostream>
#include <queue>
#include <vector>

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

    while(!traversal.empty()){
        TreeNode* temp = traversal.front();
        traversal.pop();
        cout << temp->value << endl;
        if(temp->left != NULL){
            traversal.push(temp->left);
        }
        if(temp->right != NULL){
            traversal.push(temp->right);
        }
    }
}

void levelOrder(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> traversal;
    vector<TreeNode*> layer;
    traversal.push(root);
    layer.push_back(root);

    while(!traversal.empty()){
        int layerSize = layer.size();
        for(int i=0; i<layerSize; i++){
            TreeNode* temp = traversal.front();
            traversal.pop();
            cout << temp->value << " ";
            // layer.erase(layer.begin()+i);
            if(temp->left != NULL){
                traversal.push(temp->left);
                layer.push_back(temp->left);
            }
            if(temp->right != NULL){
                traversal.push(temp->right);
                layer.push_back(temp->right);
            }
        }
        layer.erase(layer.begin(), layer.begin()+layerSize);
        cout<<endl;
    }
}

int main(){
    cout << "BFS: " << endl;
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

    // BFS(head);
    levelOrder(head);
    return 0;
}