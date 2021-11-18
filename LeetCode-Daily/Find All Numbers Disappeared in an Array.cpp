//Problem Link:https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

//QUES

/*Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/

/***************************CODE********************/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        
        vector<int> res;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=-1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
 