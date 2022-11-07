#include<iostream>
using namespace std;

// @Leetcode
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        if(root==NULL) return root;
        if(root==p || root==q) return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        return left && right ? root: left ? left : right ? right: NULL;
    }