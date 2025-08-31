class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:
    bool backtrack(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, r, c, ch)) {
                            board[r][c] = ch;
                            if (backtrack(board)) return true;
                            board[r][c] = '.'; // undo (backtrack)
                        }
                    }
                    return false; // no valid number found → backtrack
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false; // row
            if (board[i][c] == ch) return false; // col
            int rowStart = 3 * (r / 3), colStart = 3 * (c / 3);
            int subRow = rowStart + i / 3, subCol = colStart + i % 3;
            if (board[subRow][subCol] == ch) return false; // 3x3 sub-box
        }
        return true;
    }
};
