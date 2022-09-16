#include<iostream>
#include<vector>
using namespace std; 
 

// Leetcode
// Boyr moore voting algorithm

 int majorityElement(vector<int>& nums) {
        int el=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==el) count++;
            else{
                if(count==1){
                    el=nums[i];
                    count=1;
                } 
                else{
                    count--;
                }
            }
        }
        return el;
    }