//Problem Link:https://leetcode.com/problems/sort-characters-by-frequency/

//QUES
/* Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

 Return the sorted string. If there are multiple answers, return any of them.*/
/**********************CODE********************/

class Solution {
public:
    
     static bool cmp(pair<char,int>&a, pair<char,int>&b){
        if(a.second>b.second){
            return true;
        }
        return false;
    }
    string frequencySort(string s) {
        
        
        int n = s.length();
        
        vector<pair<int,char>>  vp(123,{0,0}); 
       
        for(int i=0;i<n;i++){
            vp[s[i]] = {vp[s[i]].first+1,s[i]};
        }

        sort(vp.begin(),vp.end());
      
        string res="";
        for(int i=vp.size()-1;i>=0;i--){
            while(vp[i].first>0){
                res+=vp[i].second;
                vp[i].first--;
            }
        }
        return res;
        
    }
};