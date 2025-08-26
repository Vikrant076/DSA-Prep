class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = 0;
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diagSq = l * l + w * w;  // diagonal^2
            int area = l * w;

            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
