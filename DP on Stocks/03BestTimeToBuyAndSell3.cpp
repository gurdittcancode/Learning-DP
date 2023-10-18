/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/

class Solution {
public:

    int f(int day, int action, vector<int> &prices, vector<vector<int>> &dp) {
        if(day == prices.size() || action == 4) return 0;

        if(dp[day][action] != -1) return dp[day][action];

        int ans = 0;
        
        if(action % 2 == 0) {
            //we may buy
            ans = max(-prices[day] + f(day + 1, action + 1, prices, dp), f(day + 1, action, prices, dp));
        }
        else {
            //we may sell
            ans = max(prices[day] + f(day + 1, action + 1, prices, dp), f(day + 1, action, prices, dp));
        }

        return dp[day][action] = ans;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for(int day = n-1; day >= 0; day--) {
            for(int action = 0; action <= 3; action++) {
                int ans = 0;
                if(action % 2 == 0) {
                    //we can buy
                    ans = max(-prices[day] + dp[day + 1][action + 1], dp[day + 1][action]);
                }
                else {
                    //we can sell
                    ans = max(prices[day] + dp[day + 1][action + 1], dp[day + 1][action]);
                }

                dp[day][action] = ans;
            }
        }

        return dp[0][0];
    }
};