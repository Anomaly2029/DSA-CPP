class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(int i, int j, string &s, string &p) {

        if (memo[i][j] != -1)
            return memo[i][j];

        if (j == p.size())
            return memo[i][j] = (i == s.size());

        bool firstMatch =
            (i < s.size()) &&
            (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*') {

            return memo[i][j] =
                dfs(i, j + 2, s, p) ||
                (firstMatch && dfs(i + 1, j, s, p));

        } else {

            return memo[i][j] =
                firstMatch &&
                dfs(i + 1, j + 1, s, p);
        }
    }

    bool isMatch(string s, string p) {

        memo.assign(s.size() + 1,
                    vector<int>(p.size() + 1, -1));

        return dfs(0, 0, s, p);
    }
};