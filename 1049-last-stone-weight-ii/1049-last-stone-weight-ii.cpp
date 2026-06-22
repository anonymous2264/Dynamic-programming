class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int s = target; s >= stone; s--) {
                dp[s] = dp[s] || dp[s - stone];
            }
        }

        int best = 0;
        for (int s = target; s >= 0; s--) {
            if (dp[s]) {
                best = s;
                break;
            }
        }

        return totalSum - 2 * best;
    }
};