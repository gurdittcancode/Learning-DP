// Same as house robber, but now neighbourhood is circular
// (first and last house are adjacent)

class Solution {
public:

    int compute(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int i = 1; i<n; i++) {
            int take = nums[i] + (i > 1 ? prev2 : 0);
            int notTake = 0 + prev;

            int curi = max(take, notTake);

            prev2 = prev;
            prev = curi;
        }  

        return prev;
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0; i<n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(compute(temp1), compute(temp2));
    }
};