//Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

//QUES

/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.*/


/*************************CODE**********************/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        
        int low = 0,high = nums.size()-2,mid;
        
        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid]==nums[mid^1]){
                low = mid+1;
            }
            else{
                high =  mid - 1;
            }
            
        }
        
        return nums[low];
    }
};
