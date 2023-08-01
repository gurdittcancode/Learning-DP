class Solution {
public:

    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return grid[0][0];

        if(i < 0 || j < 0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, grid, dp);
        int left = f(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(m - 1, n - 1, grid, dp);        

        // vector<vector<int>> dp(m, vector<int>(n));

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(i == 0 && j == 0) {
        //             dp[i][j] = grid[i][j];
        //         }
        //         else {
        //             int up = grid[i][j];
        //             up += i > 0 ? dp[i-1][j] : 1e9;

        //             int left = grid[i][j];
        //             left += j > 0 ? dp[i][j-1] : 1e9;

        //             dp[i][j] = min(up, left);
        //         }
        //     }
        // }

        // return dp[m-1][n-1];

        //SPACE-OPTIMIZED
        vector<int> prev(n);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n);

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                }
                else {
                    int up = grid[i][j];
                    up += i > 0 ? prev[j] : 1e9;

                    int left = grid[i][j];
                    left += j > 0 ? curr[j-1] : 1e9;

                    curr[j] = min(up, left);
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};