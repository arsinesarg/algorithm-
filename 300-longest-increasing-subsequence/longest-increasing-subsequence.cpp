#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> tails;
        for (int x : nums) {
            auto it = std::lower_bound(tails.begin(), tails.end(), x);
            
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        
        return tails.size();
    }
};