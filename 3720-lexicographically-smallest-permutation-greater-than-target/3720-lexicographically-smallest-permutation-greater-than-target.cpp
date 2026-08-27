class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string prefix;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // We can keep this position equal to target
            if (cnt[x] > 0) {
                prefix += target[i];
                cnt[x]--;
                continue;
            }

            // Cannot stay equal.
            // Try the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = prefix;
                ans += char('a' + c);

                cnt[c]--;

                // Smallest possible suffix
                for (int j = 0; j < 26; j++) {
                    ans.append(cnt[j], char('a' + j));
                }

                return ans;
            }

            // No greater character at this position.
            // We must backtrack.
            break;
        }

        /*
         * We couldn't make the answer greater at the current position.
         * Go backwards and try to increase an earlier character.
         */
        for (int i = prefix.size() - 1; i >= 0; i--) {

            // Put prefix[i] back into available characters.
            cnt[prefix[i] - 'a']++;

            int x = target[i] - 'a';

            // Try the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans = prefix.substr(0, i);
                ans += char('a' + c);

                cnt[c]--;

                // Fill remaining characters in sorted order.
                for (int j = 0; j < 26; j++) {
                    ans.append(cnt[j], char('a' + j));
                }

                return ans;
            }
        }

        return "";
    }
};