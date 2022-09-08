#include<iostream>
#include<vector>
using namespace std;


vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
        ans.push_back(a[n-1]);
        int maxEl=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>=maxEl) ans.push_back(a[i]);
            maxEl=max(maxEl,a[i]);
        }
   
        int i=0,j=ans.size()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        return ans;
        
    }