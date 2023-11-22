class Solution {
public:

    bool isPalindrome(int s, int e, string &str) {
        while(s < e) {
            if(str[s] != str[e]) return false;
            s++; e--;
        }
        return true;
    }

    int f(int idx, int n, string &str, vector<int> &dp) {
        
        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;
        for(int j = idx; j<n; j++) {
            if(isPalindrome(idx, j, str)) {
                //valid cut
                int cost = 1 + f(j + 1, n, str, dp);
                ans = min(ans, cost);
            }
        }

        return dp[idx] = ans;
    }

    int minCut(string str) {
        int n = str.size();
        // vector<int> dp(n, -1);
        // return f(0, n, str, dp) - 1;
        //it's doing an extra partition at the (n-1)th partition, so exclude that

        vector<int> dp(n + 1, 0);
        
        for(int i = n-1; i >= 0; i--) {
            int ans = INT_MAX;
            for(int j = i; j<n; j++) {
                if(isPalindrome(i, j, str)) {
                    int cost = 1 + dp[j + 1];
                    ans = min(ans, cost);
                }
            }
            dp[i] = ans;
        }

        return dp[0] - 1;
    }
};