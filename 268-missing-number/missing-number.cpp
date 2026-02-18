#include <vector>
#include <algorithm>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            int correctIndex = nums[i];
            if (nums[i] < n && nums[i] != nums[correctIndex]) {
                std::swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                return i;
            }
        }
        
        return n;
    }
};