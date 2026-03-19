#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();

        if (m < n) return minDistance(word2, word1);

        std::vector<int> dp(n + 1);

        for (int j = 0; j <= n; ++j) {
            dp[j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            int prev_diag = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev_diag;
                } else {
                    dp[j] = 1 + std::min({dp[j], dp[j - 1], prev_diag});
                }
                prev_diag = temp;
            }
        }

        return dp[n];
    }
};