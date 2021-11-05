//Problem Link:https://leetcode.com/problems/arranging-coins/

/*You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.
*/

/*************************CODE*********************/

class Solution {
public:
    int arrangeCoins(int n) {
        
        long long low = 1 , high = n,ans;
        
        while(low<=high){
            
            long long mid = low + (high -low)/2;
            
            if((mid*(mid+1))/2<=n){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

 
