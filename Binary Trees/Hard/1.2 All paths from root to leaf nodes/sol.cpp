#include<iostream>
#include<vector>
using namespace std;


// @GFG
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void findAllPaths(Node *root,vector<vector<int>>& ans,vector<int> &temp){
    if(root==NULL) return;
    if(!root->left && !root->right){
        temp.push_back(root->data);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    
    temp.push_back(root->data);
    findAllPaths(root->left,ans,temp);
    findAllPaths(root->right,ans,temp);
    temp.pop_back();
}

vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<int> temp;
    vector<vector<int>> ans;
    findAllPaths(root,ans,temp);
    return ans;
}