class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // lcms[size] = LCMs of all subsets having 'size' coins
        vector<vector<long long>> lcms(n + 1);

        // Precompute LCM for every subset
        for (int mask = 1; mask < (1 << n); mask++) {
            long long curLCM = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    curLCM = lcm(curLCM, coins[i]);
                }
            }

            lcms[bits].push_back(curLCM);
        }

        // Count how many valid amounts <= x
        auto count = [&](long long x) {
            long long cnt = 0;

            for (int size = 1; size <= n; size++) {
                for (long long L : lcms[size]) {
                    long long ways = x / L;

                    if (size & 1)
                        cnt += ways;
                    else
                        cnt -= ways;
                }
            }

            return cnt;
        };

        // kth answer cannot exceed k * minimum coin
        long long low = 1;
        long long high = 1LL * k *
                         (*min_element(coins.begin(), coins.end()));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

