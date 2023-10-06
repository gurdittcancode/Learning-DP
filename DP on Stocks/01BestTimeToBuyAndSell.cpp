#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int mini = prices[0];
    int profit = 0;
    
    for(int i = 1; i<n; i++) {
        if(mini <= prices[i]) {
            profit = max(profit, prices[i] - mini);
        }

        if(prices[i] < mini) mini = prices[i];
    }

    return profit;
}