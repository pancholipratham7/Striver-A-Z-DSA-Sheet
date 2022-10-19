#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

 string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> temp;
        for(auto it:m){
            temp.push(make_pair(it.second,it.first));
        }
        
        while(!temp.empty()){
            for(int i=0;i<temp.top().first;i++){
                ans+=temp.top().second;
            }
            temp.pop();
        }
        return ans;
    }