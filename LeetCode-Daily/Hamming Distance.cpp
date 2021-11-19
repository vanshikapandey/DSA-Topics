//Problem Link:https://leetcode.com/problems/hamming-distance/

//QUES

/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.*/

/******************CODE**********************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int cnt = 0;
        
        int xr = x^y;
        
        for(int i=0;i<32;i++){
            int mask = 1<<i;
            if(mask&xr){
                cnt++;
            }
        }
        return cnt;
    }
};

