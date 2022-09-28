#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            if(i>2){
                int n=ans.size()-1;
                for(int j=1;j<ans[n].size();j++){
                    temp.push_back(ans[n][j]+ans[n][j-1]);
                }
            }
            if(i>1) temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }