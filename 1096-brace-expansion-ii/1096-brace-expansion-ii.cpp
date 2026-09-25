class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            }
            else {
                set<string> next;

                if (s[i] == '{') {
                    i++; 
                    next = parse(s, i);
                    i++; 
                }
                else {
                    next.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;

                for (auto &a : cur)
                    for (auto &b : next)
                        temp.insert(a + b);

                cur = temp;
            }
        }

        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};