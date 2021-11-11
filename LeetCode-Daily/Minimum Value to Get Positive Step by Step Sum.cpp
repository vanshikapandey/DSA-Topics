//Problem Link: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

//QUES

/*Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.*/



/*************CODE*************/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
     
        int minm = nums[0], prefixSum = nums[0]; 
        for(int i=1;i<nums.size();i++){
            prefixSum+=nums[i];
            minm = min(minm,prefixSum);
        }
        // cout<<minm;
        if(minm>=1){
            return 1;
        }
        return abs(minm)+1;
    }
};