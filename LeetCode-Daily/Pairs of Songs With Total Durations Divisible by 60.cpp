//Problem Link:https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

//QUES

/*You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.*/


/**********CODE***********/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        map<int,int> mp;
        
        int n = time.size();
        for(int i=0;i<n;i++){
            mp[time[i]%60]++;
        }
        
        int ans = 0;
        
         if(mp[0]>0){
                ans+=(mp[0])*(mp[0]-1)/2;
            }
         if(mp[30]>0){
                ans+=(mp[30])*(mp[30]-1)/2;
            }
        for(auto e:mp){
         if(mp.find(60-e.first)!=mp.end() && e.first!=30 && e.first!=0 && e.first<=30){
                ans+=e.second*mp[60-e.first];
            }
        }
        
        return ans;
    }
};
