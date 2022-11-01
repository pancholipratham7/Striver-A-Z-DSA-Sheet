#include<iostream>
#include<vector>
using namespace std;

 template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool isLeaf(TreeNode<int> *curr){
    if(!curr->left && !curr->right) return true;
    return false;
}
void addLeftBoundary(TreeNode<int>* root,vector<int> &ans){
    TreeNode<int> *curr=root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void addRightBoundary(TreeNode<int> *root,vector<int> &ans){
    if(root==NULL) return;
    if(!root->left && !root->right) return;
    if(root->right) addRightBoundary(root->right,ans);
    else addRightBoundary(root->left,ans);
    ans.push_back(root->data);
}

void addLeafNodes(TreeNode<int> *root,vector<int> &ans){
    if(root==NULL) return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    addLeafNodes(root->left,ans);
    addLeafNodes(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    if(!root->left && !root->right) {
        ans.push_back(root->data);
        return ans;
    }
    ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeafNodes(root,ans);
    addRightBoundary(root->right,ans);
    return ans;
}