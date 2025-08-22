class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        if (rows.empty()) return 0; // no 1s

        int minRow = *min_element(rows.begin(), rows.end());
        int maxRow = *max_element(rows.begin(), rows.end());
        int minCol = *min_element(cols.begin(), cols.end());
        int maxCol = *max_element(cols.begin(), cols.end());

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

        return height * width;
    }
};
