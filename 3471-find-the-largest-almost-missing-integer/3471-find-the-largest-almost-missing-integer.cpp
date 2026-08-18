class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> count;
        unordered_map<int, int> lastRight;

        int ans = -1;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int l = max(0, i - k + 1);
            int r = min(i, n - k);

            if (!count.count(x)) {
                count[x] = r - l + 1;
                lastRight[x] = r;
            } 
            else {
                if (l > lastRight[x] + 1) {
                    count[x] += r - l + 1;
                } 
                else if (r > lastRight[x]) {
                    count[x] += r - lastRight[x];
                }

                lastRight[x] = r;
            }
        }

        for (auto &[x, c] : count) {
            if (c == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};