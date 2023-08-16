/*This solution is absolutely correct, not getting submitted on CodeStudio for some 
reason

  https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
  
*/

int minSubsetSumDifference(vector<int>& arr, int n) {
	// Write your code here.
  int sum = 0;
  for(int i = 0; i<n; i++) sum += arr[i];
  
  int k = sum;
  
  // vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
  
  // for(int i = 0; i<n; i++) dp[i][0] = true;
  // if(arr[0] <= k) dp[0][arr[0]]= true;

  // for(int i = 1; i<n; i++) {
  //   for(int target = 1; target <= k; target++) {
  //     bool notPick = dp[i-1][target];
  //     bool pick = false;
  //     if(arr[i] <= target) pick = dp[i-1][target - arr[i]];
      
  //     dp[i][target] = pick || notPick;
  //   }
  // }

  // int mini = 1e9;
  //   for(int s1 = 0; s1 <= k/2; s1++) {
  //     if(dp[n-1][s1] == true) {
  //       mini = min(mini, abs((sum - s1) - s1));
  //     }
  // }

  vector<bool> prev(k+1, 0), cur(k+1, 0);
  prev[0] = cur[0] = true;

  if(arr[0] <= k) prev[arr[0]] = true;

  for(int idx = 1; idx<n; idx++) {
    for(int target = 1; target<=k; target++) {
      bool notTake = prev[target];
      bool take = false;
      if(arr[idx] <= target) take = prev[target - arr[i]];

      cur[idx] = notTake || take;
    }
    prev = cur;
  }

  int mini = 1e9;
  for(int s1 = 0; s1 <= k/2; s1++) {
    if(prev[s1] == true) {
      mini = min(mini, abs((sum - s1) - s1));
    }
  }

  return mini;
}