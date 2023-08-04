//can start from any cell in first row, can end at any cell in final row (variable start & end points)
#include <bits/stdc++.h> 

int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp) {

    if(j < 0 || j >= a[0].size()) return -1e9;

    if (i == 0) return a[0][j];

    if(dp[i][j] != -1) return dp[i][j];

    int u = a[i][j] + f(i-1, j, a, dp);
    int ld = a[i][j] + f(i-1, j-1, a, dp);
    int rd = a[i][j] + f(i-1, j+1, a, dp);

    return dp[i][j] = max(u, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &a)
{
    //  Write your code here.

    int m = a.size();
    int n = a[0].size();
    
    // vector<vector<int>> dp(m, vector<int>(n, -1));

    // int maxi = -1e9;

    // for(int j = 0; j < n; j++) {
    //     maxi = max(maxi, f(m-1, j, a, dp));
    // }

    // return maxi;

    //ITERATIVE DP
    // vector<vector<int>> dp(m, vector<int>(n));

    // dp[0] = a[0];

    // for(int i = 1; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         int u = a[i][j] + dp[i-1][j];
    //         int ld = a[i][j] + (j - 1 >= 0 ? dp[i-1][j-1] : -1e9);
    //         int rd = a[i][j] + (j + 1 < n ? dp[i-1][j+1] : -1e9);

    //         dp[i][j] = max(u, max(ld, rd));
    //     }

    // }

    // int maxi = *(max_element(dp[m-1].begin(), dp[m-1].end()));

    // return maxi;


    //SPACE-OPTIMIZED

    vector<int> prev(n), cur(n);
    prev = a[0];

     for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int u = a[i][j] + prev[j];
            int ld = a[i][j] + (j - 1 >= 0 ? prev[j-1] : -1e9);
            int rd = a[i][j] + (j + 1 < n ? prev[j+1] : -1e9);

            cur[j] = max(u, max(ld, rd));
        }
        prev = cur;
    }

    int maxi = *(max_element(prev.begin(), prev.end()));

    return maxi;
}