//Problem Link:https://leetcode.com/problems/largest-component-size-by-common-factor/

//QUES

/*You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.*/

/*****************CODE*****************/



class Solution {
public:
    int find(int child,vector<int> & parent){
       
        if(parent[child]==-1){
            return child;
        }
        parent[child] = find(parent[child], parent);
        return parent[child];
    }
    
    void unite(int x,int y, vector<int>& parent){
        int xparent = find(x,parent);
        int yparent = find(y,parent);
        
        if(xparent!=yparent){
            parent[yparent] = xparent;
        }
    }
    int largestComponentSize(vector<int>& nums) {
       
        vector<int> parent(200001,-1);
        
        for(int i=0;i<nums.size();i++){
            for(int j = 2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    unite(j,nums[i],parent);
                    unite(nums[i],nums[i]/j,parent);
                }
            }
        }
    
        map<int,int> mp;
        int cnt  = 0;
        for(int i=0;i<nums.size();i++){
            int par = find(nums[i],parent);
                
            cnt =  max(cnt,1 + mp[par]);
            mp[par]++;
        }
        
        return cnt;
        
    }
};