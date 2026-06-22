class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        for (int num : nums) {
            points[num] += num;
        }
        int prev2 = points[0];
        int prev1 = max(points[0], points[1]);
        for (int i = 2; i <= maxVal; i++) {
            int current = max(prev1, points[i] + prev2);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};