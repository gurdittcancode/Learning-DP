//https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

int lcs(string &s, string &t){

    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int j = 0; j<=n; j++) dp[0][j] = 0;
    for(int i = 0; i<=m; i++) dp[i][0] = 0;

    int ans = 0;

    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;

    //space optimized
    vector<int> prev(n+1, 0), cur(n+1, 0);

    int ans = 0;

    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }

    return ans;

}