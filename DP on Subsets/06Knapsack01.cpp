//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542

#include <bits/stdc++.h> 

int f(int idx, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
	if(idx == 0) {
            return wt[idx] <= W ? val[idx] : 0;
    }

	if(dp[idx][W] != -1) return dp[idx][W];
        
    int notPick = 0 + f(idx - 1, W, wt, val, dp);
    int pick = INT_MIN;
	if(wt[idx] <= W) {
        pick = val[idx] + f(idx - 1, W - wt[idx], wt, val, dp);
    }
        
    return dp[idx][W] = max(pick, notPick);
}

int knapsack(vector<int> wt, vector<int> val, int n, int W) {

	// Write your code here
	// vector<vector<int>> dp(n, vector<int>(W+1, -1));
	// return f(n-1, W, weights, values, dp);

	// ITERATIVE DP
	vector<vector<int>> dp(n, vector<int>(W+1));
	
	for(int w = wt[0]; w<=W; w++) dp[0][w] = val[0];

	for(int i = 1; i<n; i++) {
		for(int w = 0; w<=W; w++) {
			int notPick = dp[i-1][w];
			int pick = INT_MIN;
			if(wt[i] <= w) {
				pick = val[i] + dp[i-1][w-wt[i]];
			}

			dp[i][w] = max(pick, notPick);
		}
	}

	return dp[n-1][W];

	//SPACE OPTIMIZATION

	vector<int> prev(W+1), cur(W+1);
	for(int w = wt[0]; w<=W; w++) prev[w] = val[0];

	for(int i = 1; i<n; i++) {
		for(int w = 0; w<=W; w++) {
			int notPick = prev[w];
			int pick = INT_MIN;
			if(wt[i] <= w) pick = val[i] + prev[w-wt[i]];

			cur[w] = max(pick, notPick);
		}
		prev = cur;
	}

	return prev[W];

	//EVEN MORE SPACE OPTIMIZATION WTF
	vector<int> prev(W+1);
	for(int w = wt[0]; w<=W; w++) prev[w] = val[0];

	for(int i = 1; i<n; i++) {
		for(int w = W; w >= 0; w--) {
			int notPick = prev[w];
			int pick = INT_MIN;
			if(wt[i] <= w) pick = val[i] + prev[w-wt[i]];

			prev[w] = max(pick, notPick);
		}
	}

	return prev[W];
}