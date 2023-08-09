//From Code Studio, like House Robber from LeetCode

/*
	1 2 4
	ans -> 5 (1 + 4)
*/

/*

1. try out all subsequences, pick the one with maximum sum
	(Recursion)

	pick/non-pick
*/

int f(vector<int>& nums, int idx, vector<int>& dp) {
    if(idx < 0) return 0;
    if(idx == 0) return nums[0]; //we could only reach here if we didn't pick up
                                // nums[1]

    if(dp[idx] != -1) return dp[idx];

    int pick = nums[idx] + f(nums, idx - 2, dp);
    int notPick = 0 + f(nums, idx - 1, dp);

    return dp[idx] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // vector<int> dp(nums.size(), -1);
    // return f(nums, nums.size() - 1, dp);

    // vector<int> dp(nums.size());
    dp[0] = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        int pick = nums[i];
        pick += i -2 >= 0 ? dp[i-2] : 0;

        int notPick = 0 + dp[i-1];
        dp[i] = max(pick, notPick);
    }

    return dp[nums.size() - 1];

    //SPACE OPTIMIZE
    int prev = nums[0]; //for i = 1
    int prev2 = 0;

    int n = nums.size();

    for(int i = 1; i<n; i++) {
        int pick = nums[i] + prev2;
        int notPick = 0 + prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }    

    return prev;
}