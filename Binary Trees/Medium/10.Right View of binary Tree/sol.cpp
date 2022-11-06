#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;

// @lEETCODE

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void findRightSideView(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        map<int,int> nodes;
        queue<pair<int,TreeNode*>> temp;
        temp.push({0,root});
        while(!temp.empty()){
            auto node=temp.front();
            if(node.second->left) temp.push({node.first+1,node.second->left});
            if(node.second->right) temp.push({node.first+1,node.second->right});
            nodes[node.first]=node.second->val;
            temp.pop();
        }
        for(auto el:nodes) ans.push_back(el.second);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        findRightSideView(root,ans);
        return ans;
    }