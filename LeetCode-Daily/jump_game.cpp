//Problem Link:https://leetcode.com/problems/jump-game/

//QUES
/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.*/

/************************code************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int lastGood = 0;
        for(int i = n-2;i>=0;i--){
            cout<<nums[i]<<" "<<lastGood<<endl;
            if(nums[i]>=(n-i-1-lastGood)){
                lastGood = n-i-1;
            }
        }
        // cout<<lastGood;
        return lastGood==n-1;
    }
};
