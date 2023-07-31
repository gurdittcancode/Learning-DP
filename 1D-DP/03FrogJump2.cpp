/*
	https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include<bits/stdc++.h>
using namespace std;

int costRecursive(vector<int>& heights, int n , int k, int idx, vector<int>& dp) {
	if(idx == 0) return 0;

	if(dp[idx] != -1) return dp[idx];

	int ans = INT_MAX;

	for(int i = 1; i<=k; i++) {
		if(idx - i >= 0) {
			ans = min(ans, abs(heights[idx] - heights[idx-i]) + costRecursive(heights, n, k, idx - i, dp));
		}
	}

	return dp[idx] = ans;
}


int main() {

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif

	int n, k; cin >> n >> k;
	vector<int> heights(n);
	for(int i = 0; i<n; i++) cin >> heights[i];

	// vector<int> dp(n, -1);

	// cout << costRecursive(heights, n, k, n-1, dp);

	// ITERATIVE DP
	vector<int> dp(n);
	dp[0] = 0;
	for(int i = 1; i<n; i++) {
		int ans = INT_MAX;
		for(int j = 1; j<=k; j++) {
			if(i - j >= 0) {
				ans = min(ans, abs(heights[i] - heights[i-j]) + dp[i-j]);
			}
		}
		dp[i] = ans;
	}

	cout << dp[n-1];

	//SPACE-OPTIMIZED
	/* 
		We need to store result of last k elements
		but if k = n, you aren't really optimizing
	*/

	// 	vector<int> dp(k);
	// dp[0] = 0;
	// for(int i = 1; i<n; i++) {
	// 	int curi = i;
	// 	int prev = i-1;
	// 	int ans = INT_MAX;
	// 	for(int j = 1; j<=k; j++) {
	// 		if(i - j >= 0) {
	// 			ans = min(ans, abs(heights[i] - heights[i-j]) + dp[i-j]);
	// 		}
	// 	}
	// 	prev = curi;
	// 	dp.erase(dp.begin());
	// 	dp.push_back(curi);
	// }

	// cout << dp[n-1];

	return 0;
}