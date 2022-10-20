 #include<iostream>
 using namespace std;
 
// @lEETCODE
 int maxDepth(string s) {
        int outerArrows=0;
        int maxD=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') outerArrows++;
            else if(s[i]==')'){
                maxD=max(maxD,outerArrows);
                outerArrows--;
            }
        }
        return maxD;
    }