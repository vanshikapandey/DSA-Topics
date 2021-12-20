//Problem Link:https://leetcode.com/problems/minimum-absolute-difference/

//QUES

/*Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr*/


/***********CODE*************/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
     
        sort(arr.begin(),arr.end());
        
        vector<vector<int>> res;
        
        int n = arr.size() , gap =INT_MAX;;
        
        for(int i=0;i<n-1;i++){
            if(gap>(arr[i+1]-arr[i])){
                while(res.size()!=0){
                    res.pop_back();
                }
                gap = arr[i+1]-arr[i];
                vector<int> temp={arr[i],arr[i+1]};
                res.push_back(temp);
            }
            else if(gap==(arr[i+1]-arr[i])){
                vector<int> temp={arr[i],arr[i+1]};
                res.push_back(temp);
            }
        }
        
        return res;
    }
};

