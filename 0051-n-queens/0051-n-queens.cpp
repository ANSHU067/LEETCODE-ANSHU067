class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, int n,
               vector<string>& board,
               vector<vector<string>>& ans) {

        // All queens placed
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for(int col = 0; col < n; col++) {

            if(isSafe(board, row, col, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next row
                solve(row + 1, n, board, ans);

                // BACKTRACK
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(
            n,
            string(n, '.')
        );

        solve(0, n, board, ans);

        return ans;
    }
};