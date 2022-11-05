#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// GFG
 void findTopView(Node *root,vector<int> &ans){
        if(root==NULL) return;
        map<int,int> nodes;
        queue<pair<int,Node*>> temp;
        nodes[0]=root->data;
        if(root->left)
            temp.push({-1,root->left});
        if(root->right)
            temp.push({1,root->right});
        int maxLeft=0;
        int maxRight=0;
        while(!temp.empty()){
            if(temp.front().first<maxLeft){
                nodes[temp.front().first]=temp.front().second->data;
                maxLeft=temp.front().first;
            }
            else if(temp.front().first>maxRight){
                nodes[temp.front().first]=temp.front().second->data;
                maxRight=temp.front().first;
            }
            if(temp.front().second->left){
                temp.push({temp.front().first-1,temp.front().second->left});
            }
            if(temp.front().second->right){
                temp.push({temp.front().first+1,temp.front().second->right});
            }
            temp.pop();
        }
        
        for(auto it:nodes){
            ans.push_back(it.second);
        }
    }
    
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        findTopView(root,ans);
        return ans;
    }