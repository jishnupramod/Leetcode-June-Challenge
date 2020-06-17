/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/


class Solution {
private:
    int flag = 0;
    void dfs(vector<vector<char>>& b, int i, int j, int r, int c, char sym) {
        if (i<0 or i>=r or j<0 or j>=c or b[i][j] != 'O')
            return;
        b[i][j] = sym;
        dfs(b, i+1, j, r, c, sym);
        dfs(b, i-1, j, r, c, sym);
        dfs(b, i, j+1, r, c, sym);
        dfs(b, i, j-1, r, c, sym);
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size(), cnt = 0;
        int c = r == 0 ? 0 : board[0].size();
        for (int i=0; i<r; ++i) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, r, c, '#');
            if (board[i][c-1] == 'O')
                dfs(board, i, c-1, r, c, '#');
        }
        for (int j=0; j<c; ++j) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, r, c, '#');
            if (board[r-1][j] == 'O')
                dfs(board, r-1, j, r, c, '#');
        }
        for (int i=1; i<r-1; ++i) {
            for (int j=1; j<c-1; ++j) {
                if (board[i][j] == 'O') {
                    dfs(board, i, j, r, c, 'X');
                }
            }
        }
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};