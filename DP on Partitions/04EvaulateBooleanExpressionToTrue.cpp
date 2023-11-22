#include<bits/stdc++.h>

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    // Iterate through the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        //We are doing this calculation because for eg, 2 T's aren't the only way to make an OR expression TRUE

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            //only T & T = T so add only these 2 numbers
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            //F & T = T & F = F & F = F so add up all the ways
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            //F | T = T | F = T | T = T so add up all the ways
            else ways = (ways + (lF * rF) % mod) % mod;
            //only F | F = F so add only these 2 numbers
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            //T ^ F = F ^ T = T so add up all the ways
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
            //F ^ F = T ^ T = F so add up all the ways

        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    // Write your code here. 
    int n = exp.size();
    // return f(0, n-1, true, exp, dp);

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    for(int i = 0; i<n; i++) {
        dp[i][i][1] = exp[i] == 'T';
        dp[i][i][0] = exp[i] == 'F';

        for(int i = n-1; i>=0; i--) {
            for(int j = i; j<n; j++) {
                for(int isTrue = 0; isTrue<=1; isTrue++) {
                    if(i == j) {
                        if(isTrue) dp[i][j][isTrue] = exp[i] == 'T';
                        else dp[i][j][isTrue] = exp[i] == 'F';
                        continue;
                    }
                    //not same
                    ll ways = 0;
                    for(int ind = i + 1; ind<j; ind+=2) {
                        ll lT = dp[i][ind - 1][1];
                        ll lF = dp[i][ind - 1][0];
                        ll rT = dp[ind + 1][j][1];
                        ll rF = dp[ind + 1][j][0];

                        if (exp[ind] == '&') {
                            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                        }
                        else if (exp[ind] == '|') {
                            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                            else ways = (ways + (lF * rF) % mod) % mod;
                        }
                        else {  // XOR operator
                            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                        }    
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n-1][1];
    }
}