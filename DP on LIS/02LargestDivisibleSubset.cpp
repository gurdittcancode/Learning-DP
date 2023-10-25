//same question as LIS, but instead of arr[idx] > arr[prev], we check for divisibility

class Solution {
public:

    vector<int> printLIS(vector<int> &arr, int n) {
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        
        for(int i = 0; i<n; i++){
            
            hash[i] = i; // initializing with current index
            for(int prev_index = 0; prev_index <= i-1; prev_index++){
                
                if(arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        
        int ans = -1;
        int lastIndex =-1;
        
        for(int i = 0; i<n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        
        return temp;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return printLIS(nums, nums.size());
    }
};