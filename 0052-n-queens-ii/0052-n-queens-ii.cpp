class Solution {
public:
    int count = 0;

    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void solve(int row, int n) {

        // All queens are successfully placed
        if (row == n) {
            count++;
            return;
        }

        // Try placing queen in every column
        for (int c = 0; c < n; c++) {

            // Check if column or diagonal is already occupied
            if (col.count(c) ||
                diag1.count(row - c) ||
                diag2.count(row + c)) {
                continue;
            }

            // Place queen
            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            // Move to next row
            solve(row + 1, n);

            // Backtrack
            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    int totalNQueens(int n) {
        solve(0, n);
        return count;
    }
};