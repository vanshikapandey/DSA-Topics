//Problem Link:https://leetcode.com/problems/domino-and-tromino-tiling/

//QUES

/*You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
*/


/**************CODE************/
class Solution {
public:
  
    int dp[1001][2], mod = 1e9 + 7;
    int numTilings(int n) {
        if(n<=2) return n;
        memset(dp,-1,sizeof(dp));
        return dfs(n,1);
    }
    
    long dfs(int n, bool done){
        
        if (n<0) return 0;
        if (n==0) return done;

        
        if (dp[n][done]!= -1) return dp[n][done];
        
        long ans = 0;
        if (done)
            ans += dfs(n-1, 1) + dfs(n-2,1) + 2 * dfs(n-2,0);
        else{
            ans +=  dfs(n-1,0) + dfs(n-1,1);
        }
        return dp[n][done] = ans % mod;
    }
};