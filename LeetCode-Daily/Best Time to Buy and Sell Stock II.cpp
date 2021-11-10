//Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//QUES

/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.*/


/*******************CODE***************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
         int sum = 0;
        if(is_sorted(prices.begin(),prices.end())){
            for(int i=1;i<prices.size();i++){
                sum+=prices[i]-prices[i-1];
            }
            
            return sum;
        }
        
        for(int i = 1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0){
                sum+=(prices[i]-prices[i-1]);
            }
        }
        
        return sum;
    }
};