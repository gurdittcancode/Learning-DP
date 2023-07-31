#include<bits/stdc++.h>
using namespace std;

int fiboRecursive(int n, vector<int>& dp) {
	if(n <= 1) return n;

	if(dp[n] != -1) return dp[n];

	return dp[n] = fiboRecursive(n-1, dp) + fiboRecursive(n-2, dp);
}

int fiboIterative(int n) {
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int fiboSpaceOptimized(int n) {
	int prev2 = 0;
	int prev1 = 1;

	for(int i = 2; i<=n; i++) {
		int curi = prev1 + prev2;
		prev2 = prev1;
		prev1 = curi;
	}

	return prev1;
}

int main() {
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int n; cin >> n;

	vector<int> dp(n+1, -1);

	cout << fiboRecursive(n, dp) << endl;
	cout << fiboIterative(n) << endl;
	cout << fiboSpaceOptimized(n) << endl;

	return 0;
}