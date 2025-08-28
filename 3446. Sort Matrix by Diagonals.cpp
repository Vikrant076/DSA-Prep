class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid;
        
        // Process bottom-left triangle (including main diagonal)
        for (int d = 0; d < n; d++) {
            vector<int> diagonal;
            // Extract diagonal starting from (d, 0)
            for (int i = d, j = 0; i < n && j < n; i++, j++) {
                diagonal.push_back(grid[i][j]);
            }
            // Sort in non-increasing order for bottom-left
            sort(diagonal.rbegin(), diagonal.rend());
            
            // Put back sorted values
            int idx = 0;
            for (int i = d, j = 0; i < n && j < n; i++, j++) {
                grid[i][j] = diagonal[idx++];
            }
        }
        
        // Process top-right triangle (excluding main diagonal)
        for (int d = 1; d < n; d++) {
            vector<int> diagonal;
            // Extract diagonal starting from (0, d)
            for (int i = 0, j = d; i < n && j < n; i++, j++) {
                diagonal.push_back(grid[i][j]);
            }
            // Sort in non-decreasing order for top-right
            sort(diagonal.begin(), diagonal.end());
            
            // Put back sorted values
            int idx = 0;
            for (int i = 0, j = d; i < n && j < n; i++, j++) {
                grid[i][j] = diagonal[idx++];
            }
        }
        
        return grid;
    }
};
