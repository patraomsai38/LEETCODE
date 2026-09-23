class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;

        for (int v : nums)
            total += v;

        long long target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int left = 0, ans = -1;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target)
                sum -= nums[left++];

            if (sum == target)
                ans = max(ans, right - left + 1);
        }

        return ans == -1 ? -1 : n - ans;
    }
};