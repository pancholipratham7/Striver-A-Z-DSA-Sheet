  #include<iostream>
  #include<climits>
  using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    int findMaxPath(TreeNode *root,int &maxSum){
        if(root==NULL) return INT_MIN;
        int pathSum=root->val;
        int lh=findMaxPath(root->left,maxSum);
        int rh=findMaxPath(root->right,maxSum);
        if(lh>0) pathSum+=lh;
        if(rh>0) pathSum+=rh;
        maxSum=max(maxSum,pathSum);
        if(max(lh,rh)>0) return max(lh,rh)+root->val;
        return root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        findMaxPath(root,maxSum);
        return maxSum;
    }