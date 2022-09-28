#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int target;
            if(nums[i]>=0){
                target=-nums[i];
            }
            else{
                target=abs(nums[i]);
            }
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(l!=i+1 && nums[l]==nums[l-1]){
                    l++;
                    continue;
                }
                if(nums[l]+nums[r]==target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]>target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }