class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // If we take all stones
        int best = stones[n - 1];

        // Process possible moves from right to left
        for (int i = n - 2; i >= 1; i--) {
            best = max(best, stones[i] - best);
        }

        return best;
    }
};