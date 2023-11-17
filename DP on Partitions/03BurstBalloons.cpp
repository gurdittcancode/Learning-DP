class Solution {
public:

    int f(int L, int R, vector<int> &nums) {
        if(L > R) return 0;

        int ans = INT_MIN;
        for(int k = L; k<=R; k++) {
            int coins = f(L, k - 1, nums) + f(k + 1, R, nums) + (L - 1 >= 0 ? nums[L - 1] : 1) * nums[k] * (R + 1 < nums.size() ? nums[R + 1] : 1);

            ans = max(ans, coins);
        }

        return ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // return f(0, n-1, nums);

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int L = n - 1; L >= 0; L--) {
            for(int R = L; R<n; R++) {
                int ans = INT_MIN;
                for(int k = L; k <= R; k++) {
                    int coins = (k - 1 >= 0 ? dp[L][k - 1] : 0) + (k + 1 < n ? dp[k + 1][R] : 0) + (L - 1 >= 0 ? nums[L - 1] : 1) * nums[k] * (R + 1 < n ? nums[R + 1] : 1);
                    ans = max(ans, coins);
                }
                dp[L][R] = ans;
            }
        }

        return dp[0][n - 1];
    }
};