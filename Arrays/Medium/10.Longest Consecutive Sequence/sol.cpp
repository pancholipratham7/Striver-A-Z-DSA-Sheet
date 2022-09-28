  #include<iostream>
  #include<vector>
  #include<algorithm>
  using namespace std;
  
  int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int count=1;
        int maxCount=1;
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]) continue;
           if(nums[i]==nums[i-1]+1){
               count++;
               maxCount=max(maxCount,count);
           }
           else count=1;
        }
        return maxCount;
    }