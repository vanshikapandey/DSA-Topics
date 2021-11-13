//Problem Link:https://leetcode.com/problems/daily-temperatures/

//QUES

/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.*/

/****************************CODE*******************************/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res;
        
        stack<pair<int,int>> st;
        int n = temperatures.size();
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                res.push_back(0);
                st.push({temperatures[i],i});
            }
            else if(st.top().first>temperatures[i]){
                res.push_back(st.top().second-i);
                st.push({temperatures[i],i});
            }
            else if(st.top().first<=temperatures[i]){
                while(st.size()>0 && st.top().first<=temperatures[i]){
                    st.pop();    
                }
                
                if(st.empty()){
                   res.push_back(0); 
                }
                else{
                    res.push_back(st.top().second-i);
                }
                
                st.push({temperatures[i],i});
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};