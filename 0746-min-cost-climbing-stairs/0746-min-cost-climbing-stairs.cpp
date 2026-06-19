class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
        // prev2 = min cost to reach two steps back, prev1 = min cost to reach one step back
        int prev2 = 0, prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int current = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};