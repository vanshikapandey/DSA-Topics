//Problem  Link: https://leetcode.com/problems/unique-paths/

//QUES

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

/**************CODE********************/

class Solution {
public:
    int dp[101][101];
    int paths(int m ,int n){
        
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0)
            return 0;
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n] = paths(m-1,n) + paths(m,n-1);
        
        
    }
    int uniquePaths(int m, int n) {
        
        memset(dp,-1,sizeof(dp));
        return paths(m-1,n-1);
    }
};