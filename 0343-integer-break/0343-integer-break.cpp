class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int j = 3; j <= n; j++) {
            for (int i = 1; i < j; i++) {
                // Either keep (j - i) whole or use its optimal break
                dp[j] = max(dp[j], i * max(j - i, dp[j - i]));
            }
        }
        return dp[n];
    }
};