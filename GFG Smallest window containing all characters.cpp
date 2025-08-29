#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (s.size() < p.size()) return "";
        
        vector<int> need(26, 0), window(26, 0);
        for (char c : p) need[c - 'a']++;
        
        int required = 0; 
        for (int x : need) if (x > 0) required++; 
        
        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX, start = 0;
        
        while (r < (int)s.size()) {
            int idx = s[r] - 'a';
            window[idx]++;
            
            if (need[idx] > 0 && window[idx] == need[idx]) {
                formed++;
            }
            
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                
                int leftIdx = s[l] - 'a';
                window[leftIdx]--;
                if (need[leftIdx] > 0 && window[leftIdx] < need[leftIdx]) {
                    formed--;
                }
                l++;
            }
            
            r++;
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
