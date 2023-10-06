//https://www.codingninjas.com/studio/problems/minimum-elements_3843091

#include <bits/stdc++.h> 

int f(int idx, int X, vector<int> &nums, vector<vector<int>> &dp) {
    if(idx == 0) {
        if(X % nums[0] == 0) return X / nums[0];
        else return 1e9;
    }

    if(dp[idx][X] != -1) return dp[idx][X];

    int notPick = 0 + f(idx - 1, X, nums, dp);
    int pick = INT_MAX;
    if(nums[idx] <= X) pick = 1 + f(idx, X - nums[idx], nums, dp);

    return dp[idx][X] = min(pick, notPick);
}

int minimumElements(vector<int> &nums, int T) {
    // Write your code here.
    int n = nums.size();

    // vector<vector<int>> dp(n, vector<int>(x+1, -1));

    // int ans = f(n - 1, x, nums, dp);
    // if(ans >= 1e9) return -1;

    // return ans;

    //ITERATIVE DP
    // vector<vector<int>> dp(n, vector<int>(T + 1));

    // for(int t = 0; t<=T; t++) {
    //     if(t % nums[0] == 0) dp[0][t] = t / nums[0];
    //     else dp[0][t] = 1e9;
    // }

    // for(int idx = 1; idx<n; idx++) {
    //     for(int t = 0; t<=T; t++) {
    //         int notPick = dp[idx-1][t];
    //         int pick = INT_MAX;
    //         if(nums[idx] <= t) pick = 1 + dp[idx][t - nums[idx]];

    //         dp[idx][t] = min(pick, notPick);
    //     }
    // }

    // return dp[n-1][T] >= 1e9 ? -1 : dp[n-1][T];

    //SPACE OPTIMIZED
    vector<int> prev(T+1), cur(T+1);
    for(int i = 0; i<=T; i++) {
        if(i % nums[0] == 0) prev[i] = i/nums[0];
        else prev[i] = 1e9;
    }

    for(int idx = 1; idx<n; idx++) {
        for(int t = 0; t<=T; t++) {
            int notPick = 0 + prev[t];
            int pick = INT_MAX;
            if(nums[idx] <= t) pick = 1 + cur[t - nums[idx]];

            cur[t] = min(pick, notPick);
        }
        prev = cur;
    }

    return prev[T] >= 1e9 ? -1 : prev[T];
}