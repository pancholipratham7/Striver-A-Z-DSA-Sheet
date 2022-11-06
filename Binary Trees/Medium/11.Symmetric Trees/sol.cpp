 #include<iostream>
 using namespace std;


// @Leetcode
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 bool findSymmetry(TreeNode *root1,TreeNode *root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val!=root2->val) return false;
        return findSymmetry(root1->left,root2->right) && findSymmetry(root1->right,root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(!root->left && !root->right) return true;
        return findSymmetry(root->left,root->right);
    }