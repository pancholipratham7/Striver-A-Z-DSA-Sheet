#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

//@Leetcode
struct Node{
    int data;
    Node *left;
    Node *right;
};

 void findBottomView(Node *root,vector<int> &ans){
            if(root==NULL) return;
            map<int,int> nodes;
            queue<pair<int,Node*>> temp;
            nodes[0]=root->data;
            if(root->left)
                temp.push({-1,root->left});
            if(root->right)
                temp.push({1,root->right});
            while(!temp.empty()){
                auto el=temp.front();
                if(el.second->left)
                    temp.push({el.first-1,el.second->left});
                if(el.second->right)
                    temp.push({el.first+1,el.second->right});
                nodes[el.first]=el.second->data;
                temp.pop();
            }
            for(auto it:nodes){
                ans.push_back(it.second);
            }
    }
  
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        findBottomView(root,ans);
        return ans;
    }