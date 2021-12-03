//Problem Link:https://leetcode.com/problems/maximum-product-subarray/

//QUES

/***************CODE**************/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int mini = 1 , maxi = 1;
        int res = *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                mini = 1;
                maxi = 1;
            }
            int temp = nums[i]*maxi;
            maxi = max(nums[i]*mini,max(nums[i]*maxi,nums[i]));
            mini = min(nums[i]*mini,min(temp,nums[i]));
            
            res = max(res,max(maxi,mini));
        }
        
        return res;
    }
};
