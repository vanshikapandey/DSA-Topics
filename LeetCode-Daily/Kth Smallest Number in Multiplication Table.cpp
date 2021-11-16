//Problem Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

//QUES:

/*Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

 */

 /****************CODE*******************/

 class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int low = 1, high = m*n;
        
        while(low<=high){
            
            int total = 0;
            int target = low + (high - low)/2;
            
            for(int i=1;i<=m;i++){
                total+=min(target/i,n);
            }
            
           if(total<k){
                low = target+1;
            }
            else{
                high = target-1;
            } 
        }
        
        return low;
    }
};
