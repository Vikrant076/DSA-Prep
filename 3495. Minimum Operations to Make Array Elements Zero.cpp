class Solution {
public:
    using ll = long long;

    // Compute total steps from 1..n
    ll prefixSteps(long long n) {
        if (n <= 0) return 0;
        ll res = 0;
        long long start = 1;
        int k = 1;
        while (start <= n) {
            long long end = min(n, (1LL << (2 * k)) - 1); // 4^k - 1 = (1<<(2k)) - 1
            long long cnt = end - start + 1;
            res += cnt * 1LL * k;
            start <<= 2; // move to next block (multiply by 4)
            k++;
        }
        return res;
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ll total = prefixSteps(r) - prefixSteps(l - 1);
            ans += (total + 1) / 2;  // ceil division
        }
        return ans;
    }
};
