//Problem Link:https://leetcode.com/problems/largest-divisible-subset/

//QUES

/*Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.*/

/**********************CODE***************************/

class Solution {
public:
  
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> res;
        sort(nums.begin(),nums.end());
        
        
        int n = nums.size();
        
        if(n==1){
            return nums;
        }
        
        vector<int> dp(n,0);
        
        int mx = INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                }
                mx = max(mx,dp[i]);
            }
        }
        int prev = -1;
        for(int i = n-1;i>=0;i--){
            if(mx==dp[i] && prev==-1){
              res.push_back(nums[i]);
                mx-=1;
                prev = nums[i];  
            }
            if(mx == dp[i] && prev%nums[i]==0){
                res.push_back(nums[i]);
                mx-=1;
                prev = nums[i];
            }
        }      
        return res;
    }
};
