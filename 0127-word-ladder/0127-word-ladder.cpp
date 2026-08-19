class Solution {
public:
    bool isConnected(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;

            if (diff > 1)
                return false;
        }

        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        int n = wordList.size();

        int end = -1;

        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                end = i;
                break;
            }
        }

        if (end == -1)
            return 0;

        vector<string> words;
        words.push_back(beginWord);

        for (string &word : wordList)
            words.push_back(word);

        int N = words.size();

        vector<vector<int>> graph(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {

                if (isConnected(words[i], words[j])) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }

        vector<bool> visited(N, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int node = q.front();
                q.pop();

                if (node == end + 1)
                    return level;

                for (int next = 0; next < N; next++) {

                    if (graph[node][next] &&
                        !visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            level++;
        }

        return 0;
    }
};