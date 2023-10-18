/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
*/

class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> cur(2, 0), next(2, 0);
        for(int day = n-1; day >= 0; day--) {
            cur[1] = max(-prices[day] + next[0], next[1]);
            cur[0] = max(prices[day] - fee + next[1], next[0]);

            next = cur;
        }

        return next[1];
    }
};