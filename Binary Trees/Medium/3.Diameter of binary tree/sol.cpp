 #include<iostream>
 using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 int maxEdgeDistance(TreeNode *root){
        if(root==NULL) return 0;
        int e1=0,e2=0;
        if(root->left) e1=1+maxEdgeDistance(root->left);
        if(root->right) e2=1+maxEdgeDistance(root->right);
        return max(e1,e2);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxD=0;
        maxD=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        int e1=0,e2=0;
        if(root->left) e1=1+maxEdgeDistance(root->left);
        if(root->right) e2=1+maxEdgeDistance(root->right);
        maxD=max(maxD,e1+e2);
        return maxD;
    }