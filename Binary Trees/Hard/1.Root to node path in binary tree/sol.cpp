#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


void findPath(TreeNode *root,int data,vector<int>& ans){
    if(root==NULL) return;
    if(root->val==data){
        ans.push_back(root->val);
        return;
    }
    ans.push_back(root->val);
    findPath(root->left,data,ans);
    if(ans.size()!=0 && ans[ans.size()-1]==data) return;
    findPath(root->right,data,ans);
    if(ans.size()!=0 && ans[ans.size()-1]==data) return;
    ans.pop_back();
} 
 
vector<int> solve(TreeNode* A, int B) {
    vector<int> ans;
    findPath(A,B,ans);
    return ans;
}
