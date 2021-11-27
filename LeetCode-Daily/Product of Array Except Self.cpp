//Problem Link:https://leetcode.com/problems/product-of-array-except-self/


//QUES



/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 */



 /*************CODE****************/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> res;
        int n = nums.size();
        long long int prod =  1;
        int cnt = count(nums.begin(),nums.end(),0);
        
        if(cnt>1){
            
            vector<int> ans(n,0);
            
            return ans;
        }
        
        int flag = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
               
                prod*=nums[i];
            }
            else{
                flag = 1; 
            }
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(flag && nums[i]==0){
                res.push_back(prod);
            }
            else if(flag && nums[i]){
                res.push_back(0);
            }
            else{
                res.push_back(prod/nums[i]);
            }
        }
        
        return res;
    }
};
