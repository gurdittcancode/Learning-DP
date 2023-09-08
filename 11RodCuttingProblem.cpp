//https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

#include<bits/stdc++.h>
using namespace std;

int f(int idx, int N, vector<int> &val, vector<vector<int>> &dp) {
	
	if(idx == 0) {
		return N * val[0];
		//N pieces of length 1, 1 length has value = val[0]. total value = N * val[0]
	}

	if(dp[idx][N] != -1) return dp[idx][N];

	int notTake = 0 + f(idx - 1, N, val, dp);
	int take = INT_MIN;
	int rodLength = idx + 1;
	if(rodLength <= N) take = val[idx] + f(idx, N - rodLength, val, dp);

	return dp[idx][N] = max(take, notTake);
}

int cutRod(vector<int> &val, int N) {
	
	int n = val.size();
	// vector<vector<int>> dp(n, vector<int>(N + 1, -1));
	// return f(n-1, N, val, dp);

	//ITERATIVE DP
	// vector<vector<int>> dp(v, vector<int>(N + 1, 0));
	// for(int n = 0; n <= N; n++) dp[0][n] = n * val[0];

	// for(int idx = 1; idx<v; idx++) {
	// 	for(int n = 0; n<=N; n++) {
	// 		int notTake = 0 + dp[idx - 1][n];
	// 		int take = INT_MIN;
	// 		int rodLength = idx + 1;
	// 		if(rodLength <= n) take = val[idx] + dp[idx][n - rodLength];

	// 		dp[idx][n] = max(take, notTake);
	// 	}
	// }

	// return dp[v-1][N];

	//SPACE-OPTIMIZED 2 vectors
	// vector<int> prev(N + 1, 0), cur(N + 1, 0);
	// for(int n = 0; n <= N; n++) prev[n] = n * val[0];

	// for(int idx = 1; idx<v; idx++) {
	// 	for(int n = 0; n<=N; n++) {
	// 		int notTake = 0 + prev[n];
	// 		int take = INT_MIN;
	// 		int rodLength = idx + 1;
	// 		if(rodLength <= n) take = val[idx] + cur[n - rodLength];

	// 		cur[n] = max(take, notTake);
	// 	}
	// 	prev = cur;
	// }

	// return prev[N];

	//SPACE-OPTIMIZED 1 vector
	vector<int> prev(N + 1, 0);
	for(int n = 0; n <= N; n++) prev[n] = n * val[0];

	for(int idx = 1; idx<v; idx++) {
		for(int n = 0; n<=N; n++) {
			int notTake = 0 + prev[n];
			int take = INT_MIN;
			int rodLength = idx + 1;
			if(rodLength <= n) take = val[idx] + prev[n - rodLength];

			prev[n] = max(take, notTake);
		}
	}

	return prev[N];
}
