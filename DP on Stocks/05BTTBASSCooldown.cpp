/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

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