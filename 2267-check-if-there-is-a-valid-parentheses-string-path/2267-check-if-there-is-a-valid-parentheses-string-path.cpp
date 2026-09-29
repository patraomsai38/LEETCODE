class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 ||
            grid[0][0] == ')' ||
            grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<char>>> vis(
            m, vector<vector<char>>(n, vector<char>(m + n, 0))
        );

        function<bool(int,int,int)> dfs = [&](int i, int j, int bal) {
            if (vis[i][j][bal])
                return false;

            vis[i][j][bal] = 1;

            bal += (grid[i][j] == '(' ? 1 : -1);

            if (bal < 0)
                return false;

            int remaining = (m - 1 - i) + (n - 1 - j);

            if (bal > remaining)
                return false;

            if (i == m - 1 && j == n - 1)
                return bal == 0;

            if (i + 1 < m && dfs(i + 1, j, bal))
                return true;

            if (j + 1 < n && dfs(i, j + 1, bal))
                return true;

            return false;
        };

        return dfs(0, 0, 0);
    }
};