// https://leetcode.com/problems/triangle/

class Solution {
public:

    int f(int m, int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == m - 1) {
            return triangle[m-1][j]; 
        }

        //j will never go out of bounds that's why no base case for it

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + f(m, i + 1, j, triangle, dp);
        int diagonal = triangle[i][j] + f(m, i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();        

        // vector<vector<int>> dp(m, vector<int>(m, -1));

        // return f(m, 0, 0, triangle, dp);

        // vector<vector<int>> dp(m, vector<int>(m));

        // for(int i = 0; i < m; i++) {
        //     dp[m-1][i] = triangle[m-1][i];
        // }
        //or ->

        // dp[m-1] = triangle[m-1]; //base case


        // for(int i = m - 2; i >= 0; i--) {
        //     for(int j = i; j >= 0; j--) {
        //         int down = triangle[i][j] + dp[i + 1][j];
        //         int dg = triangle[i][j] + dp[i + 1][j + 1];

        //         dp[i][j] = min(down, dg);
        //     }
        // }

        // return dp[0][0];

        //SPACE OPTIMIZED

        vector<int> next = triangle[m-1];
        vector<int> curr(m);

        for(int i = m - 2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {

                int down = triangle[i][j] + next[j];
                int dg = triangle[i][j] + next[j+1];

                curr[j] = min(dg, down);
            }

            next = curr;
        }

        return next[0];
    }
};