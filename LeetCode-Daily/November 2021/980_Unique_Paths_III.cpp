// Problem link: https://leetcode.com/problems/unique-paths-iii/

/*
Problem: You are given an m x n integer array grid where grid[i][j] could be:

    1 representing the starting square. There is exactly one starting square.
    2 representing the ending square. There is exactly one ending square.
    0 representing empty squares we can walk over.
    -1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Solution: We can use DFS to find all the possible path from the starting square to ending square, and return the number of all possible path 
where the number of empty square are equal to total square covered while traversing from starting point to ending point using DFS.
*/

/********************************************************----CODE---********************************************************/

class Solution {
public:
    int empty = 1, res = 0;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return;
        }
        if (grid[x][y] == 2) {
            if (count == empty) {
                res++;
            }
            return;
        }
        grid[x][y] = -1;
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        grid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int  start_x = 0, start_y = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
                if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }
        dfs(grid, start_x, start_y, 0);        
        return res;
    }
};
