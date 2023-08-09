bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0;

	for(int x : arr) sum += x;

	if(sum % 2) return false;

	int k = sum/2;

	vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = true;
    cur[0] = true;

    if(arr[0] <= k) prev[arr[0]] = true;
	
    for(int i = 1; i<n; i++) {
        for(int target = 1; target<=k; target++) {
            bool notPick = prev[target];
            bool pick = false;
            if(arr[i] <= target) pick = prev[target-arr[i]];

            cur[target] = pick || notPick;
        }
        prev = cur;
    }

    return prev[k];
}
