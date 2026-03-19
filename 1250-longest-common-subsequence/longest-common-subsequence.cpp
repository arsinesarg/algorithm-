#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.size();
        int n = text2.size();
        
        if (m < n) return longestCommonSubsequence(text2, text1);

        std::vector<int> prev(n + 1, 0);
        std::vector<int> curr(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = std::max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};