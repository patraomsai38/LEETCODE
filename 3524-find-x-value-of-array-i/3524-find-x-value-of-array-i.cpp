class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k), ndp(k);

        for (int x : nums) {
            fill(ndp.begin(), ndp.end(), 0);

            int m = x % k;
            ndp[m] = 1;

            for (int r = 0; r < k; r++)
                ndp[r * m % k] += dp[r];

            for (int r = 0; r < k; r++)
                ans[r] += ndp[r];

            dp.swap(ndp);
        }

        return ans;
    }
};