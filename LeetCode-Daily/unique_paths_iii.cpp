//Problem Link:https://leetcode.com/problems/unique-paths-iii/
//QUES
/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.
*/


/****************CODE******************/

class Solution {
public:
    int ans = 0,empty=1;
    void unique(vector<vector<int>>& grid,int m,int n,int cnt){
        
        if(m<0 || n<0 || m>=grid.size() || n>=grid[0].size() || grid[m][n]==-1){
            return ;
        }
        
        if(grid[m][n]==2){
            if(cnt==empty)
             ans++;
            return;
        }
        
        grid[m][n]=-1;
        
        unique(grid,m+1,n,cnt+1);
        unique(grid,m-1,n,cnt+1);
        unique(grid,m,n+1,cnt+1);
        unique(grid,m,n-1,cnt+1);
        
        grid[m][n] = 0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
            
            int posi,posj;
        
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                     posi=i;
                     posj=j;
                }
                if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        
        // cout<<posi<<" "<<posj;
        // return 0;
         unique(grid,posi,posj,0);
        return ans;
    }
};