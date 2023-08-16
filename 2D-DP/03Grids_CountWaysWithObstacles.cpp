//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:

    int mod = (int)(1e9 + 7);

    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;

        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, grid, dp);
        int left = f(i, j-1, grid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(m-1, n-1, grid, dp);

        vector<int> prev(n);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n);
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }

                int up = i > 0 ? prev[j] : 0;
                int left = j > 0 ? curr[j - 1] : 0;

                curr[j] = (up + left);
            }
            prev = curr;
        }

        return prev[n-1];
    }
};