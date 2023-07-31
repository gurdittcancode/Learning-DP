/*
	https://www.codingninjas.com/studio/problems/frog-jump_3621012
*/

#include <bits/stdc++.h> 

int f(int idx, vector<int>& heights, vector<int>& dp) {
    if(idx == 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int X = INT_MAX;
    if(idx - 1 >= 0) X = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx-1]);

    int Y = INT_MAX;
    if(idx - 2 >= 0) Y = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx-2]);

    return dp[idx] = min(X, Y);
}

int frogJump(int n, vector<int> &heights)
{
    //we have converted this problem to 0-based indexing

    // vector<int> dp(n, -1);
    // return f(n-1, heights, dp);

    //ITERATIVE DP

    // vector<int> dp(n);
    // dp[0] = 0;

    // for(int i = 1; i<n; i++) {
    //     int x = abs(heights[i] - heights[i-1]) + dp[i-1];
    //     int y = i > 1 ? abs(heights[i] - heights[i-2]) + dp[i-2] : INT_MAX;
    //     dp[i] = min(x, y);
    // }

    // return dp[n-1];

    //SPACE OPTIMIZED

    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i<n; i++) {
        int x = abs(heights[i] - heights[i-1]) + prev;
        int y = i > 1 ? abs(heights[i] - heights[i-2]) + prev2 : INT_MAX;
        int curi = min(x, y);

        prev2 = prev;
        prev = curi;
    }

    return prev;
}