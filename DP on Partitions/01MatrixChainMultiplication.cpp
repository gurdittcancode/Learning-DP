#include <bits/stdc++.h> 

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    //returns minimum number of multiplications needed to multiply matrices [i...j]
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int k = i; k<j; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N) {
    // // Write your code here.
    // return f(1, N - 1, arr, dp);

    //ITERATIVE DP
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for(int i = 0; i<N; i++) dp[i][i] = 0; //base case, not needed as already initialized

    for(int i = N-1; i>=1; i--) {
        for(int j = i + 1; j<N; j++) {
            int mini = 1e9;
            for(int k = i; k<j; k++) {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}