#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// @Leetcode
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         vector<int> ans;
        if(k==0){
            ans.push_back(target->val);
            return ans;
        }
        queue<TreeNode*> temp;
        unordered_map<TreeNode*,TreeNode*> parent;
        temp.push(root);
        while(!temp.empty()){
            TreeNode *front=temp.front();
            if(front->left) {
                parent[front->left]=front;
                temp.push(front->left);
            }
            if(front->right){
                parent[front->right]=front;
                temp.push(front->right);
            }
            temp.pop();
        }

        queue<pair<TreeNode *,int>> nodeInfo;
        unordered_map<TreeNode*,bool> visited;
        nodeInfo.push({target,0});
        while(!nodeInfo.empty()){
            int dist=nodeInfo.front().second;
            TreeNode *node=nodeInfo.front().first;
            if(dist==k){
                ans.push_back(node->val);
            }
            else{
                    if(node->left && !visited[node->left]) nodeInfo.push({node->left,dist+1});
                    if(node->right && !visited[node->right]) nodeInfo.push({node->right,dist+1}); 
                    if(parent[node] && !visited[parent[node]]) nodeInfo.push({parent[node],dist+1});
            }
            visited[node]=true;
            nodeInfo.pop();
        }
        return ans;
    }