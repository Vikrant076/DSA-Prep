class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;
        
        while (right < n) {
            // Count zeros in the current window
            if (arr[right] == 0) {
                zeroCount++;
            }
            
            // Shrink the window if zero count exceeds k
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update the maximum length of valid window
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength;
    }
};
