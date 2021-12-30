//Problem Link:https://leetcode.com/problems/smallest-integer-divisible-by-k/

//QUES


/*Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.*/

/************************CODE*************************/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if(k%2==0 || k%5==0){
            return -1;
        }
        int remainder = 1 , cnt = 1;
        while(true){
            remainder = remainder%k;
            if(remainder==0){
                return cnt;
            }
           
            remainder = (remainder*10 + 1);
            cnt++;
        }
        return -1;
        
        
    }
};