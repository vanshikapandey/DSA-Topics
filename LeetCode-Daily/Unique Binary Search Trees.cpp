//Problem Link:https://leetcode.com/problems/unique-binary-search-trees/

//QUES

/*Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.*/

/*****************CODE*****************/
class Solution {
public:
    
    int catalan[20];
    int cat(int n){
        if(n==0||n==1){
            return 1;
        }
        
        if(catalan[n]!=0){
            return catalan[n];
        }
        
            for(int i=1;i<=n;i++){
                 catalan[n]+= (cat(i-1)*cat(n-i));
            }
        return catalan[n];
    }
    int numTrees(int n) {
       
        memset(catalan,0,sizeof(catalan));
        return cat(n);
    }
};