class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] = max sum with remainder r when divided by 3
        vector<long> dp = {0, LONG_MIN, LONG_MIN};

        for (int num : nums) {
            vector<long> temp = dp;
            int r = num % 3;
            for (int i = 0; i < 3; i++) {
                int newRem = (i + r) % 3;
                dp[newRem] = max(dp[newRem], temp[i] + num);
            }
        }

        return (int) dp[0];
    }
};