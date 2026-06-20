class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0; // best from two houses back
        int prev1 = 0; // best from one house back
        for (int i = start; i <= end; i++) {
            int current = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};