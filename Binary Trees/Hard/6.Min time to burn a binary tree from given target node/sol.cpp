  #include<iostream>
  #include<queue>
  #include<unordered_map>
  using namespace std;
  
  class Node{
        public:
        int data;
        Node *left;
        Node * right;
  };
  
    Node *findTargetAddress(Node *root,int tar){
        if(root==NULL) return NULL;
        if(tar==root->data) return root;
        Node *temp=findTargetAddress(root->left,tar);
        if(temp!=NULL) return temp;
        return findTargetAddress(root->right,tar);
    }
    
    int minTime(Node* root, int tar) 
    {
        // Your code goes here
        int maxTime=0;
        queue<Node *> x;
        x.push(root);
        unordered_map<Node*,Node*> parent;
        while(!x.empty()){
            auto node=x.front();
            if(node->left){
                parent[node->left]=node;
                x.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                x.push(node->right);
            }
            x.pop();
        }
        Node *target=findTargetAddress(root,tar);
        queue<pair<Node *,int>> nodeInfo;
        nodeInfo.push({target,0});
        unordered_map<Node *,bool> visited;
        while(!nodeInfo.empty()){
            Node* node=nodeInfo.front().first;
            int time=nodeInfo.front().second;
            if(node->left && !visited[node->left]) nodeInfo.push({node->left,time+1});
            if(node->right && !visited[node->right]) nodeInfo.push({node->right,time+1});
            if(parent[node] && !visited[parent[node]]) nodeInfo.push({parent[node],time+1});
            visited[node]=true;
            maxTime=max(maxTime,time);
            nodeInfo.pop();
        }
        return maxTime;
    }