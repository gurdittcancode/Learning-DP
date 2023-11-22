class Solution {
public:

    int f(int idx, int k, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();

        if(idx == n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int max_el = INT_MIN;
        int ans = INT_MIN;


        for(int j = idx; j < min(n, idx + k); j++) {
            int len = j - idx + 1;
            max_el = max(max_el, nums[j]);
            int sum = max_el * len + f(j + 1, k, nums, dp);
            ans = max(ans, sum);
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &nums, int k) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return f(0, k, nums, dp);

        vector<int> dp(n + 1, 0);

        for(int idx = n-1; idx >= 0; idx--) {
            int max_el = INT_MIN, ans = INT_MIN;
            for(int j = idx; j < min(n, idx + k); j++) {
                int len = j - idx + 1;
                max_el = max(max_el, nums[j]);
                int sum = max_el * len + dp[j + 1];
                ans = max(ans, sum);
            }

            dp[idx] = ans;
        }

        return dp[0];
    }
};