//https://leetcode.com/problems/partition-equal-subset-sum/

bool canPartition(vector<int> &nums, int n) {
	// Write your code here.
	int sum = 0;

	for(int x : nums) sum += x;

	if(sum % 2) return false;

	int k = sum/2;

	vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = true;
    cur[0] = true;

    if(nums[0] <= k) prev[nums[0]] = true;
	
    for(int i = 1; i<n; i++) {
        for(int target = 1; target<=k; target++) {
            bool notPick = prev[target];
            bool pick = false;
            if(nums[i] <= target) pick = prev[target-nums[i]];

            cur[target] = pick || notPick;
        }
        prev = cur;
    }

    return prev[k];
}
