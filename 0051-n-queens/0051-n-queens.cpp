class Solution {
public:

    vector<vector<string>> ans;

    void solve(int row, int n,
               vector<string>& board,
               vector<int>& col,
               vector<int>& diag1,
               vector<int>& diag2) {

        // All queens placed
        if(row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for(int c = 0; c < n; c++) {

            // Check if column or diagonal is occupied
            if(col[c] == 1)
                continue;

            if(diag1[row - c + n - 1] == 1)
                continue;

            if(diag2[row + c] == 1)
                continue;

            // Place queen
            board[row][c] = 'Q';

            col[c] = 1;
            diag1[row - c + n - 1] = 1;
            diag2[row + c] = 1;

            // Go to next row
            solve(row + 1, n, board,
                  col, diag1, diag2);

            // Backtrack
            board[row][c] = '.';

            col[c] = 0;
            diag1[row - c + n - 1] = 0;
            diag2[row + c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(
            n,
            string(n, '.')
        );

        vector<int> col(n, 0);

        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);

        solve(0, n, board,
              col, diag1, diag2);

        return ans;
    }
};