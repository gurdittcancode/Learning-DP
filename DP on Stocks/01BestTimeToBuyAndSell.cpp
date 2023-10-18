/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];

        int n = prices.size();

        for(int i = 1; i<n; i++) {
            if(prices[i] >= mini) {
                profit = max(profit, prices[i] - mini);
            }

            if(prices[i] < mini) mini = prices[i];
        }

        return profit;
    }
};