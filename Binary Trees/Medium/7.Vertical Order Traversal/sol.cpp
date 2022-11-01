  #include<iostream>
  #include<map>
  #include<vector>
  #include<algorithm>
  using namespace std;

    // @leetcode
    // used map instead of unordered_map because for sorting rows and cols
    // instead of vector we can use multiset

    struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    void storeCoordinates(map<int,map<int,vector<int>>> &coordinates,TreeNode* root,int row,int col){
        if(root==NULL) return;
        coordinates[col][row].push_back(root->val);
        storeCoordinates(coordinates,root->left,row+1,col-1);
        storeCoordinates(coordinates,root->right,row+1,col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> coordinates;
        storeCoordinates(coordinates,root,0,0);
        vector<vector<int>> ans;
        for(auto it:coordinates){
            vector<int> temp;
            for(auto row :it.second ){
                sort(row.second.begin(),row.second.end());
                for(auto el:row.second){
                    temp.push_back(el);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }