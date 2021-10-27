//Problem Link:https://leetcode.com/problems/climbing-stairs/

//QUES
/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 */

 /***********************CODE******************/
 class Solution {
public:
    int dp[46];
    int climbCount(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = climbCount(n-1)+climbCount(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return climbCount(n);
    }
};