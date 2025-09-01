class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;          // element -> frequency
        map<int, set<int>> freqBuckets;       // frequency -> set of elements
        int maxFreq = 0;
        long long ans = 0;

        auto add = [&](int x) {
            int old = freq[x];
            int now = old + 1;
            freq[x] = now;

            if (old > 0) {
                freqBuckets[old].erase(x);
                if (freqBuckets[old].empty()) freqBuckets.erase(old);
            }
            freqBuckets[now].insert(x);

            maxFreq = max(maxFreq, now);
        };

        auto remove = [&](int x) {
            int old = freq[x];
            int now = old - 1;
            freq[x] = now;

            freqBuckets[old].erase(x);
            if (freqBuckets[old].empty()) freqBuckets.erase(old);

            if (now > 0) freqBuckets[now].insert(x);

            if (freqBuckets.count(maxFreq) == 0) maxFreq--; // adjust maxFreq
        };

        // First window
        for (int i = 0; i < k; i++) add(arr[i]);
        ans += *freqBuckets[maxFreq].begin();

        // Slide
        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            ans += *freqBuckets[maxFreq].begin();
        }

        return (int)ans;
    }
};
