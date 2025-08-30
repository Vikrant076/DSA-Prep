class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9,false));
        vector<vector<bool>> cols(9, vector<bool>(9,false));
        vector<vector<bool>> boxes(9, vector<bool>(9,false));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int d = c - '1';               // 0..8
                int b = (i / 3) * 3 + (j / 3); // box index 0..8
                if (rows[i][d] || cols[j][d] || boxes[b][d]) return false;
                rows[i][d] = cols[j][d] = boxes[b][d] = true;
            }
        }
        return true;
    }
};
