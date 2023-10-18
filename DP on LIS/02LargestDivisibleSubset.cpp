class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);

        sort(nums.begin(), nums.end());
        
        int maxi = 1;
        int endOfSub = 0;

        for(int i = 0; i<n; i++) {
            hash[i] = i;
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
                endOfSub = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[endOfSub]);

        while(hash[endOfSub] != endOfSub) {
            endOfSub = hash[endOfSub];
            temp.push_back(nums[endOfSub]);
        }
        return temp;
    }
};