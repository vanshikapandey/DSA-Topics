//Problem Link:https://leetcode.com/problems/interval-list-intersections/

//QUES

/*You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].*/


/**********************CODE*******************/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
     
        vector<vector<int>> res;
        
        int n = firstList.size(), m = secondList.size(),start,end;
        for(int i=0,j=0;(i<n && j<m);){
            
            vector<int> temp;
            
             start = max(firstList[i][0],secondList[j][0]);
                
            if(firstList[i][1]<secondList[j][1]){
                 end = firstList[i][1];
                i++;
            }
            else{
                 end = secondList[j][1];
                j++; 
            }
            if(start<=end){
                temp.push_back(start);
                temp.push_back(end);

                res.push_back(temp);
            }
        }
        return res;
    }
};