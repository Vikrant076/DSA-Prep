class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        long long total = 0;
        
        if (nums[0] == 0) {
            dp[0] = 1;
            total = 1;
        }
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                dp[i] = dp[i-1] + 1;
                total += dp[i];
            }
        }
        return total;
    }
};
