class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9 + 7;
        long long threeColor = 6;
        long long twoColor = 6;
        for (int i = 1; i < n; i++) {
            long long newThreeColor = (2 * threeColor + 2 * twoColor) % MOD;
            long long newTwoColor = (2 * threeColor + 3 * twoColor) % MOD;
            threeColor = newThreeColor;
            twoColor = newTwoColor;
        }
        return (int) ((threeColor + twoColor) % MOD);
    }
};