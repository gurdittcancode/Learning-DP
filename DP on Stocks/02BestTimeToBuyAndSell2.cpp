/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

class Solution {
public:

    int f(int day, bool canBuy, vector<int> &prices, vector<vector<int>> &dp) {
        
        if(day == prices.size()) return 0;

        if(dp[day][canBuy] != -1) return dp[day][canBuy];

        int ans = 0;
        if(canBuy) {
            ans = max(-prices[day] + f(day + 1, 0, prices, dp), f(day + 1, 1, prices, dp));
            //explore both possibilities -> we buy on this day, or we don't buy on this day
        }   
        else {
            //either sell on this day or don't
            ans = max(prices[day] + f(day + 1, 1, prices, dp), f(day + 1, 0, prices, dp));
        }

        return dp[day][canBuy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> agla(2, 0);

        for(int day = n - 1; day>=0; day--) {
            vector<int> cur(2, 0);
            for(int canBuy = 0; canBuy < 2; canBuy++) {

                int ans = 0;

                if(canBuy) {
                    ans = max(-prices[day] + agla[0], agla[1]);
                }
                else ans = max(prices[day] + agla[1], agla[0]);

                cur[canBuy] = ans;
            }
            agla = cur;
        }

        return agla[1];
    }
};