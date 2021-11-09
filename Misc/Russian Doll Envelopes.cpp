//Problem Link:https://leetcode.com/problems/russian-doll-envelopes/

//QUES

/*You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.*/

/************************CODE********************/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end());
        
        int n = envelopes.size();
        vector<int> lis(n+1,1);
        
        for(int i=1;i<envelopes.size();i++){
               for(int j = 0;j<i;j++){
                   if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1] && lis[i]<lis[j]+1 ){
                       lis[i] = lis[j]+1;
                   }
               }
            }
        return *max_element(lis.begin(),lis.end());
    }
};