class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            // If a single element exceeds target, no valid partition
            if (num > target) return false;
            // Iterate right to left to avoid using same element twice
            for (int j = target; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
            // Early exit if target is reachable
            if (dp[target]) return true;
        }

        return dp[target];
    }
};