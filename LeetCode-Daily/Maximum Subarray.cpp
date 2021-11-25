//Problem Link:https://leetcode.com/problems/maximum-subarray/

//QUES

/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.*/

/******************CODE**************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        int currSum = 0 , maxSum=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            
            if(currSum>maxSum){
                maxSum = currSum;
            }
            if(currSum<0){
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};