//Problem Link:https://leetcode.com/problems/jump-game-iii/


//QUES

/*Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.*/

/*****************CODE***********/

class Solution {
public:
   int dp[50005];
    bool vis[50001];
    bool checkReach(vector<int>& arr, int start){
        
        if(start<0 || start>=arr.size() || vis[start]){
            return false;
        }
        
        if(arr[start]==0){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        
        vis[start] = true;
        
        return dp[start] = checkReach(arr,start+arr[start]) || checkReach(arr,start-arr[start]);
    }
    
    bool canReach(vector<int>& arr, int start) {
      
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        return checkReach(arr,start);
    }
};