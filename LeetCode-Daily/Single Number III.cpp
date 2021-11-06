//Problem Link:https://leetcode.com/problems/single-number-iii/

/*Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 */

 /**********************code***********************/

 class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
      long  int xr = nums[0];
        
        for(int i=1;i<n;i++){
            xr = (xr^nums[i]);
        }
        
        int bit = xr & (-xr);
        
        // int mask = 1<<bit;
        int x = xr , y = xr;
        for(int i=0;i<n;i++){
            if(bit&nums[i]){
                x = x^nums[i];
            }            
            else{
                y = y^nums[i];
            }
        }
        
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        
        return ans;
    }
};