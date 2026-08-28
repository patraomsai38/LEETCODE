class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != 0)
                    return "";

                mid = 'a' + i;
                cnt[i]--;
            }
        }

        int half = n / 2;

        for (int i = 0; i < half; i++)
            cnt[target[i] - 'a'] -= 2;

        bool possible = true;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] < 0) {
                possible = false;
                break;
            }
        }

        auto build = [&](string left) {
            string ans = left;

            if (mid)
                ans += mid;

            for (int i = (int)left.size() - 1; i >= 0; i--)
                ans += left[i];

            return ans;
        };

        if (possible) {
            string left = target.substr(0, half);
            string candidate = build(left);

            if (candidate > target)
                return candidate;
        }

        for (int i = half - 1; i >= 0; i--) {
            int x = target[i] - 'a';

            cnt[x] += 2;

            bool ok = true;

            for (int j = 0; j < 26; j++) {
                if (cnt[j] < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] < 2)
                    continue;

                cnt[c] -= 2;

                string left = target.substr(0, i);
                left += char('a' + c);

                for (int j = 0; j < 26; j++)
                    left.append(cnt[j] / 2, char('a' + j));

                return build(left);
            }
        }

        return "";
    }
};