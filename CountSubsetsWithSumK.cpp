//https://www.codingninjas.com/studio/problems/number-of-subsets_3952532

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
	// if(target == 0) return 1;

	//including case where there can be 0s in array
	if(idx == 0) {
		if(target == 0 && arr[0] == 0) return 2;
		if(target == 0 || target == arr[0]) return 1;
		return 0;
	}

	// if(idx == 0) return arr[idx] == target;

	// if(dp[idx][target] != -1) return dp[idx][target];

	// int notPick = f(idx-1, target, arr, dp);
	// int pick = 0;
	// if(arr[idx] <= target) pick = f(idx-1, target - arr[idx], arr, dp);

	// return dp[idx][target] = pick + notPick;

	 if(target==0)
        return 1;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int>& arr, int k) {
	int n = arr.size();
	// vector<vector<int>> dp(n, vector<int>(k+1, -1));
	// return f(n-1, k, arr, dp);

	// vector<vector<int>> dp(n, vector<int>(k+1));

	vector<int> prev(k+1), cur(k+1);

	prev[0] = 1;
	cur[0] = 1;
	
	if(arr[0] <= k) prev[arr[0]] = 1;

	for(int i = 1; i<n; i++) {
		for(int target = 0; target <= k; target++) {
			int notPick = prev[target];
			int  pick = 0;
			if(arr[i] <= target) pick = prev[target - arr[i]];

			cur[target] = pick + notPick;
		}
		prev = cur;	
	}

	return prev[k];
}
