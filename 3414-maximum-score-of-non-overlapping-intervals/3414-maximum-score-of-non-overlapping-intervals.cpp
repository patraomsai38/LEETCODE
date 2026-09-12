class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        auto vorellixan = intervals;

        int n = intervals.size();

        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1],
                    intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<int> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<vector<State>> dp(n + 1, vector<State>(5));

        const long long NEG = -(1LL << 60);

        for (int k = 1; k <= 4; k++)
            dp[0][k].score = NEG;

        for (int i = 1; i <= n; i++) {
            int start = a[i - 1][0];

            int p = lower_bound(ends.begin(), ends.begin() + i - 1, start)
                    - ends.begin();

            for (int k = 1; k <= 4; k++) {
                State skip = dp[i - 1][k];

                State take;

                if (dp[p][k - 1].score != NEG) {
                    take.score = dp[p][k - 1].score + a[i - 1][2];
                    take.ids = dp[p][k - 1].ids;
                    take.ids.push_back(a[i - 1][3]);

                    sort(take.ids.begin(), take.ids.end());
                } else {
                    take.score = NEG;
                }

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        State ans = dp[n][0];

        for (int k = 1; k <= 4; k++) {
            if (better(dp[n][k], ans))
                ans = dp[n][k];
        }

        return ans.ids;
    }
};