//https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

#include<bits/stdc++.h>

long long f(int idx, int target, int *deno, vector<vector<long long>> &dp) {
    if(target == 0) return 1;
    if(idx == 0) {
        if(target % deno[0] == 0) return 1;
        else return 0;
    }

    if(dp[idx][target] != -1) return dp[idx][target];

    long long notPick = f(idx - 1, target, deno, dp);
    long long pick = 0;
    if(deno[idx] <= target) pick = f(idx, target - deno[idx], deno, dp);

    return dp[idx][target] = pick + notPick;
}

long countWaysToMakeChange(int *deno, int n, int target)
{
    //Write your code here
    // vector<vector<long long>> dp(n, vector<long long>(value + 1, -1));
    // return f(n-1, value, deno, dp);

    //ITERATIVE DP
    vector<vector<long long>> dp(n, vector<long long>(target + 1));

    // for(int idx = 0; idx<n; idx++) dp[idx][0] = 1;
    // for(int tar = 0; tar <= target; tar++) {
    //     if(tar % deno[0] == 0) dp[0][tar] = 1;
    // }

    // for(int idx = 1; idx<n; idx++) {
    //     for(int tar = 0; tar<=target; tar++) {
    //         long long notPick = dp[idx - 1][tar];
    //         long long pick = 0;
    //         if(deno[idx] <= tar) pick = dp[idx][tar - deno[idx]];

    //         dp[idx][tar] = pick + notPick;
    //     }
    // }

    // return dp[n-1][target];

    //SPACE-OPTIMIZED DP
    vector<long long> prev(target + 1);
    prev[0] = 1;

    for(int tar = 0; tar<=target; tar++) {
        if(tar % deno[0] == 0) prev[tar] = 1;
    }

    for(int idx = 1; idx<n; idx++) {
        vector<long long> cur(target + 1);
        cur[0] = 1;
        for(int tar = 0; tar<=target; tar++) {
            long long notPick = prev[tar];
            long pick = 0;
            if(deno[idx] <= tar) pick = cur[tar - deno[idx]];

            cur[tar] = pick + notPick;
        }
        prev = cur;
    }

    return prev[target];
}