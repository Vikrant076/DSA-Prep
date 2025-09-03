#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // --- Coordinate compression ---
        vector<int> xs, ys;
        for (auto &p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        // Map each point to compressed coordinates
        vector<pair<int,int>> comp(n);
        for (int i = 0; i < n; i++) {
            int cx = lower_bound(xs.begin(), xs.end(), points[i][0]) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), points[i][1]) - ys.begin();
            comp[i] = {cx, cy};
        }

        int N = xs.size();
        int M = ys.size();

        // --- Build 2D grid ---
        vector<vector<int>> grid(N+1, vector<int>(M+1, 0));
        for (int i = 0; i < n; i++) {
            auto [cx, cy] = comp[i];
            grid[cx+1][cy+1] = 1;
        }

        // --- Build 2D prefix sum ---
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        auto rectSum = [&](int x1, int y1, int x2, int y2) {
            // inclusive coordinates
            return grid[x2][y2] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x1-1][y1-1];
        };

        long long count = 0;

        // --- Check all pairs (Alice, Bob) ---
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int ax = points[i][0], ay = points[i][1];
                int bx = points[j][0], by = points[j][1];

                // Alice must be upper-left, Bob lower-right
                if (ax <= bx && ay >= by) {
                    auto [cx1, cy1] = comp[i];
                    auto [cx2, cy2] = comp[j];

                    int x1 = min(cx1, cx2) + 1;
                    int x2 = max(cx1, cx2) + 1;
                    int y1 = min(cy1, cy2) + 1;
                    int y2 = max(cy1, cy2) + 1;

                    int total = rectSum(x1, y1, x2, y2);
                    if (total == 2) count++;
                }
            }
        }

        return (int)count;
    }
};
