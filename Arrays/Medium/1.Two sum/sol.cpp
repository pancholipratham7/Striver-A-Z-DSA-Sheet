#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m[target-nums[i]]!=0 || (i!=0 && nums[0]+nums[i]==target)){
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            else{
                   m[nums[i]]=i; 
            }
        }
         return ans;
    }