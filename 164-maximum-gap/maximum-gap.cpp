class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = nums[0], maxVal = nums[0];
        for (int x : nums) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }

        if (minVal == maxVal) return 0;

        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> minBucket(bucketCount, INT_MAX);
        vector<int> maxBucket(bucketCount, INT_MIN);

        for (int x : nums) {
            int idx = (x - minVal) / bucketSize;
            minBucket[idx] = min(minBucket[idx], x);
            maxBucket[idx] = max(maxBucket[idx], x);
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            if (minBucket[i] == INT_MAX) continue;

            maxGap = max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};