#include<iostream>
#include<math.h>
using namespace std;


// @Leetcode
// T(n)=O(logn^2)
class TreeNode{
    public:
    TreeNode *left;
    TreeNode *right;
    int data;
};

 int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int leftH=0;
        int rightH=0;
        TreeNode *temp=root;
        while(temp!=NULL) {
            temp=temp->left;
            leftH++;
        }
        temp=root;
        while(temp!=NULL){
            temp=temp->right;
            rightH++;
        }
        if(leftH==rightH) return pow(2,leftH)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }