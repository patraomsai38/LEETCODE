class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];

            if (c >= 2 && c <= 9)
                rows[r] |= (1 << c);
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[row, mask] : rows) {
            bool left  = (mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))) == 0;
            bool right = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;
            bool middle = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;

            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};