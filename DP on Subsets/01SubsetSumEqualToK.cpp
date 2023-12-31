//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h>
using namespace std;

bool f(int idx, int target, int n, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) return true;
    if(idx == 0) return arr[0] == target;

    if(dp[idx][target] != -1) return dp[idx][target];

    bool notPick = f(idx-1, target, n, arr, dp);
    bool pick = false;

    if(target >= arr[idx]) pick = f(idx-1, target-arr[idx], n, arr, dp);

    return dp[idx][target] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // vector<vector<int>> dp(n, vector<int>(target+1, -1));
    //because we want to return dp[n-1][target], not dp[n-1][target-1]
    // return f(n-1, target, n, arr, dp);

    // vector<vector<bool>> dp(n, vector<bool>(target+1, 0));

    // for(int i = 0; i<n; i++) dp[i][0] = true;

    // dp[0][arr[0]] = true;

    // for(int i = 1; i<n; i++) {
    //     for(int t = 1; t<=target; t++) {
    //         bool notPick = dp[i-1][t];
    //         bool pick = false;
    //         if(arr[i] <= t) pick = dp[i-1][t-arr[i]];

    //         dp[i][t] = pick || notPick;
    //     }
    // }

    // return dp[n-1][target];

    //space-optimized
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = true;
    cur[0] = true;

    if(arr[0] <= k) prev[arr[0]] = true;
    //prev is of size k. if arr[0] = 10 and k = 4, prev[10] is out of bounds.

    //THE ZERO'TH INDEX OF CUR NEEDS TO BE MARKED TRUE (BASE CASE)

    for(int i = 1; i<n; i++) {
        for(int target = 1; target<=k; target++) {
            bool notPick = prev[target];
            bool pick = false;
            if(arr[i] <= target) pick = prev[target-arr[i]];

            cur[target] = pick || notPick;
        }
        prev = cur;
    }

    return prev[k];
}

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        vector<int> cur(2, 0), front1(2, 0), front2(2, 0);

        for(int day = prices.size()-1; day >= 0; day--) {

            cur[1] = max(-prices[day] + front1[0], front1[1]);
            cur[0] = max(prices[day] + front2[1], front1[0]);

            front2 = front1;
            front1 = cur;
        }

        return front1[1];
    }
};