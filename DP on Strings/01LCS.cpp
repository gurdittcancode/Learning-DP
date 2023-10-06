//https://www.codingninjas.com/studio/problems/longest-common-subsequence_1063255

#include <bits/stdc++.h> 

// int f(int idx1, int idx2, string &str1, string &str2, vector<vector<int>> &dp) {

//   if(idx1 < 0 || idx2 < 0) return 0;

//   if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

//   int match = 0;
//   if(str1[idx1] == str2[idx2]) match = 1 + f(idx1 - 1, idx2 - 1, str1, str2, dp);
//   int notMatch = max(f(idx1 - 1, idx2, str1, str2, dp), f(idx1, idx2 - 1, str1, str2, dp));

//   return dp[idx1][idx2] = max(match, notMatch);
// }

//after shifting indices
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

  if(i == 0 || j == 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int match = 0;
  if(s[i-1] == t[j-1]) match = 1 + f(i - 1, j - 1, s, t, dp);
  int notMatch = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));

  return dp[i][j] = max(match, notMatch);
}

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.

  int m = str1.size();
  int n = str2.size();

  // vector<vector<int>> dp(m, vector<int>(n, -1));

  // return f(m-1, n-1, str1, str2, dp);

  //ITERATIVE DP
  vector<vector<int>> dp(m+1, vector<int>(n+1));

  //don't need to write base case as they are already initialized
  // for(int j = 0; j<=n; j++) dp[0][j] = 0;
  // for(int i = 0; i<=m; i++) dp[i][0] = 0;

  // for(int i = 1; i<=m; i++) {
  //   for(int j = 1; j<=n; j++) {
  //     int match = 0;
  //     if(s[i-1] == t[j-1]) match = 1 + dp[i - 1][j - 1];

  //     int notMatch = max(dp[i - 1][j], dp[i][j - 1]);

  //     dp[i][j] = max(match, notMatch);
  //   }
  // }

  // return dp[m][n];

  //SPACE OPTIMIZED
  vector<int> prev(n+1, 0), cur(n+1, 0);

  //don't need to write base case as they are already initialized
  for(int j = 0; j<=n; j++) prev[j] = 0;
  
  for(int i = 1; i<=m; i++) {
    for(int j = 1; j<=n; j++) {
      if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
      else cur[j] = max(prev[j], cur[j-1]);
    }
    
    prev = cur;
  }

  return prev[n];
}