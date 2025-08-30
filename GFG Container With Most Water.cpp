class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxWater = max(maxWater, height * width);
            
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};
