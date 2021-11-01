/*
Problem Link: https://leetcode.com/problems/surrounded-regions/

Problem:
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Solution:
This problem can be solved by first identifying all the 'O's region which are not completely surrounded by 'X' and 
then converting all the remaining 'O's with 'X's.
We can see that 'O's which are present on the edge of the grid are not completly surrounded by 'X', so we can perform
DFS on that 'O' to identify all the 'O's which are connected to that, i.e. they are in the same region, and then mark 
them as '1'.
Later we will convert all the remaining 'O's which aren't marked with '1' to 'X' as they are completly surrounded with 
'X' and covert '1' to 'O' as we can not capture them.
*/

/***************************************************---CODE---***************************************************/

class Solution {
public:    
    void dfs(vector<vector<char>>& board, int x, int y) {
        // perform DFS if the element on the edge is 'O'
        if (board[x][y] == 'O') {
            board[x][y] = '1';
            // checking for below element
            if (x+1 < board.size()) {
                dfs(board, x+1, y);
            }
            // checking for above element
            if (x-1 > 0) {
                dfs(board, x-1, y);
            }
            // checking for left element
            if (y+1 < board[x].size()) {
                dfs(board, x, y+1);
            }
            // checking for right element
            if (y-1 > 0) {
                dfs(board, x, y-1);
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        // initialising r and c with row size and column size respectivily
        int r = board.size(), c = board[0].size();
        
        // for first row and last row
        for (int i = 0; i < r; i++) {
            dfs(board, i, 0);
            dfs(board, i, c-1);
        }
        
        // for first column and last column
        for (int j = 1; j < c-1; j++) {
                dfs(board, 0, j);
                dfs(board, r-1, j);
        }
        
        // converting 'O' into 'X' and '1' into 'O'
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
            
        }
           
    }
    
};
