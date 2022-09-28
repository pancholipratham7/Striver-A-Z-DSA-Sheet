#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posI=0;
        int negI=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) {
                ans[posI]=nums[i];
                posI+=2;
            }
            else{
                ans[negI]=nums[i];
                negI+=2;
            }
        }
        return ans;
    }