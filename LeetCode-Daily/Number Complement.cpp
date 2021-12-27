//Problem Link:https://leetcode.com/problems/number-complement/


/*The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.*/

/*************CODE************/

class Solution {
public:
    int findComplement(int num) {
     
        unsigned int temp = num ,power2 = 2;
        
        while(temp>>1){
            power2 = power2<<1;
            temp = temp>>1;
        }
        
        return power2 - num - 1;
    }
};