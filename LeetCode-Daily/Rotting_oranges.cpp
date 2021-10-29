//Problem Link:https://leetcode.com/problems/rotting-oranges/

//QUES
/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1
*/

/******************CODE***************/
class Solution {
public:
    bool isValid(int x, int y ,int n,int m){
        if(x>=0 && x<n && y>=0 && y<m){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int time = 0,total = 0,rotten;
        
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    total++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            
            int size = q.size();
            rotten+=size;
            
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int xnew = x + dx[i];
                    int ynew = y + dy[i];
                    
                    if(isValid(xnew,ynew,n,m) && grid[xnew][ynew] == 1){
                        q.push({xnew,ynew});
                        grid[xnew][ynew] = 2;
                    }
                }  
            }
            if(!q.empty())
                time++;
        }
        
        // cout<<total<<" "<<rotten;
        if(rotten==total){
            return time;
        }
        
        return -1;
    }
};