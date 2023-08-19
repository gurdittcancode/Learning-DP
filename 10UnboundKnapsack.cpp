#include<bits/stdc++.h>

int f(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if(idx == 0) {
        return ((int)(W / wt[0])) * val[0];
    }

    if(dp[idx][W] != -1) return dp[idx][W];

    int notTake = 0 + f(idx - 1, W, val, wt, dp);
    int take = 0;
    if(wt[idx] <= W) take = val[idx] + f(idx, W - wt[idx], val, wt, dp);

    return dp[idx][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // return f(n-1, W, val, wt, dp);

    //ITERATIVE DP
    // vector<vector<int>> dp(n, vector<int>(W + 1));
    // for(int w = 0; w<=W; w++) dp[0][w] = ((int)(w / wt[0])) * val[0];

    // for(int idx = 1; idx<n; idx++) {
    //     for(int w = 0; w<=W; w++) {
    //         int notTake = 0 + dp[idx - 1][w];
    //         int take = 0;
    //         if(wt[idx] <= w) take = val[idx] + dp[idx][w - wt[idx]];

    //         dp[idx][w] = max(take, notTake);
    //     }
    // }

    // return dp[n-1][W];

    //SPACE OPTIMIZED
    // vector<int> prev(W+1), cur(W+1);
    // for(int w = 0; w<=W; w++) prev[w] = ((int)(w / wt[0])) * val[0];

    // for(int idx = 1; idx<n; idx++) {
    //     for(int w = 0; w<=W; w++) {
    //         int notTake = 0 + prev[w];
    //         int take = 0;
    //         if(wt[idx] <= w) take = val[idx] + cur[w - wt[idx]];

    //         cur[w] = max(take, notTake);
    //     }
    //     prev = cur;
    // }    

    // return prev[W];

    //SPACE OPTIMIZED TO 1 VECTOR
    // We don't require the entire previous array, just the guy that is directly
    //above the cell which we are filling at a point. so we don't need the values 
    //which are behind prev[W]

    vector<int> cur(W+1,0);
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        cur[i] = ((int)i/wt[0]) * val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = cur[cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]];
                
            cur[cap] = max(notTaken, taken);
        }
    }
    
    return cur[W];
}