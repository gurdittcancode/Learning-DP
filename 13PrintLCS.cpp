//https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383

string findLCS(int m, int n, string &s, string &t){

  vector<vector<int>> dp(m+1, vector<int>(n+1));
  for(int j = 0; j<=n; j++) dp[0][j] = 0;
  for(int i = 0; i<=m; i++) dp[i][0] = 0;

  for(int i = 1; i<=m; i++) {
    for(int j = 1; j<=n; j++) {
      if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1];

      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  string ans = "";
  int i = m, j = n;
  while(i > 0 && j > 0) {
    if(s[i-1] == t[j-1]) {
      ans += s[i-1];
      i--; j--;
    } else {
      if(dp[i][j-1] > dp[i-1][j]) {

        //we will find a longer common subseq. if we move j back, so please do that

        j--;
      } else i--;
    }
  }

  reverse(ans.begin(), ans.end());
  // cout << ans << endl;
  return ans;
}