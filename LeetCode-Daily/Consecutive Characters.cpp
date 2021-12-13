//Problem Link:https://leetcode.com/problems/consecutive-characters/

//QUES

/*The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.*/

/*************CODE************/

class Solution {
public:
    int maxPower(string s) {
        
        int n = s.length();
        
        int mx = 0;
        for(int i=0,j=0;j<n;j++){
            if(s[j]==s[i]){
                 mx = max(mx,j-i+1);
            }
            else{
                i=j;
            }
           
        }
        
        return mx;
    }
};