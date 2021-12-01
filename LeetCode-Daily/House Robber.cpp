//Problem Link:https://leetcode.com/problems/house-robber/

//QUES



/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
/******************CODE***************/

class Solution {
public:
    int dp[105];
    int robbery(vector<int>& nums,int index){
        
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        return dp[index] =  nums[index] + max(robbery(nums,index+2),robbery(nums,index+3));
    }
    
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        int mx = INT_MIN;
        
        for(int i = 0;i<nums.size();i++){
            mx = max(mx,robbery(nums,i));
        }
        return mx;
    }
};
