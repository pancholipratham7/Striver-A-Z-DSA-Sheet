#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

// Leetcode
int beautySum(string s) {
        // Your code goes here
          int count=0;
        for(int i=0;i<s.length();i++){
            int freq[26]={0};
            int maxF=0;
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                int maxF=INT_MIN;
                int minF=INT_MAX;
                for(int i=0;i<26;i++){
                    maxF=max(maxF,freq[i]);
                    if(freq[i]!=0)
                       minF=min(minF,freq[i]);
                }
                count+=(maxF-minF);
            }
        }
        return count;
    }