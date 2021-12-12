//Problem Link:https://leetcode.com/problems/partition-equal-subset-sum/

//QUES


/*Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.*/

/**************CODE***********/

class Solution {
public:
    
    int dp[20005][205];
    bool Partition(vector<int>&nums,int sum,int n){
        
        if(sum==0){
            return true;
        }
        
        if(n==0){
            return false;
        }
        
        if(dp[sum][n]!=-1){
            return dp[sum][n];
        }
        
        if(sum>=nums[n]){
            return dp[sum][n] = (Partition(nums,sum-nums[n],n-1) || Partition(nums, sum, n-1)); 
        }
        
        return dp[sum][n] = Partition(nums, sum, n-1);
    }
    
    bool canPartition(vector<int>& nums) {
       
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        
        for(int  i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2){
            return false;
        }
        
        int n = nums.size()-1;
        return Partition(nums,sum/2,n);
    }
};