//https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,
        vector<vector<vector<int>>> &dp) {
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
        return -1e9;
    }

    if(i == r-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //explore all paths
    int maxi = 0;
    for(int dj1 = -1; dj1 <= 1; dj1++) {
        for(int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f(i+1, j1+dj1, j2+dj2, r, c, grid, dp);

            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int fIterative(vector<vector<int>> &grid, int r, int c) {

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));

    vector<vector<int>> front(c, vector<int>(c));
    vector<vector<int>> cur(c, vector<int>(c));

    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2) front[j1][j2] = grid[r-1][j1];
            else front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i = r-2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int maxi = 0;
                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c){
                            value += front[j1+dj1][j2+dj2];
                        }

                        maxi = max(maxi, value);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][c-1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return f(0, 0, c-1, r, c, grid, dp);
    return fIterative(grid, r, c);
}