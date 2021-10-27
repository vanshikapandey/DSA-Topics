//Problem link : https://leetcode.com/problems/longest-common-subsequence/

// QUES
/*Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings
*/

/*********************code*************************/

int dp[1001][1001];
class Solution {
public:
    
//     int lcs(string &text1, string &text2,int len1,int len2){
        
//         if(len1<0 || len2<0){
//             return 0;
//         }
        
//         if(dp[len1][len2]!=-1){
//             return dp[len1][len2];
//         }
        
//         if(text1[len1]==text2[len2]){
//             return dp[len1][len2] = 1+lcs(text1,text2,len1-1,len2-1);
//         }
        
//         return dp[len1][len2] = max(lcs(text1,text2,len1,len2-1),lcs(text1,text2,len1-1,len2));
//     }
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int i,j;
        int len1 = text1.length() , len2 = text2.length();
        
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]){
                   dp[i][j] = dp[i-1][j-1]+1; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[len1][len2];
             
    }
};