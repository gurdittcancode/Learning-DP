//https://www.codingninjas.com/studio/problems/total-unique-paths_1081470

#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& dp) {
        
    if(i == 0 && j == 0) return 1; //you have found 1 valid path, return 1

    if(i < 0 || j < 0) return 0; //don't count this path as it has taken us out of the grid!

    if(dp[i][j] != -1) return dp[i][j];

    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
    
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return f(m-1, n-1, dp);

    //ITERATIVE DP
    // vector<vector<int>> dp(m, vector<int>(n));
    // dp[0][0] = 1;

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(i == 0 && j == 0) continue; //already considered this

    //         int up = i > 0 ? dp[i-1][j] : 0;
    //         int left = j > 0 ? dp[i][j-1] : 0;
    //         dp[i][j] = up + left;
    //     }
    // }

    // return dp[m-1][n-1];

    //SPACE OPTIMIZED
    vector<int> prev(n);

    for(int i = 0; i < m; i++) {
        vector<int> curr(n);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) curr[j] = 1;
            
            else {
                int up = 0; 
                int left = 0;
                if(i > 0) up = prev[j]; //prev is already previous row
                if(j > 0) left = curr[j-1]; //curr[j-1] is the previous column
                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n-1];
}

int main() {

    int m = 5;
    int n = 10;

    cout << uniquePaths(m, n);

    return 0;
}