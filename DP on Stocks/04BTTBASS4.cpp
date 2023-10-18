/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> next(2, vector<int>(k + 1, 0)), cur(2, vector<int>(k + 1, 0));

        for(int day = n - 1; day>=0; day--) {
            for(int canBuy = 0; canBuy<=1; canBuy++) {
                for(int cap = 1; cap<=k; cap++) {
                    //if cap = 0, answer will already be 0, so why not directly start from 1?
                    int ans = 0;

                    if(canBuy) {
                        ans = max(-prices[day] + next[0][cap], next[1][cap]);
                    }
                    else {
                        ans = max(prices[day] + next[1][cap - 1], next[0][cap]);
                    }

                    cur[canBuy][cap] = ans;
                }
            }
            next = cur;
        }

        return next[1][k];
    }
};