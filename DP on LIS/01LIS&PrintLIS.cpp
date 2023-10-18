class Solution {
public:

    int f(vector<int> &arr, int n) {
        //O(n^2) time and O(2 * n) space
        vector<int> next(n+1,0);
    
        vector<int> cur(n+1,0);
        
        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
                int notTake = 0 + next[prev_index +1];
        
                int take = 0;
        
                if(prev_index == -1 || arr[ind] > arr[prev_index]){
                    
                    take = 1 + next[ind+1];
                }
        
                cur[prev_index+1] = max(notTake,take);
            }
            next = cur;
        }
        
        return cur[0];
    }

    int fLinear(vector<int> &arr, int n) {
        //O(n^2) time and O(n) space
        vector<int> dp(n,1);
    
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
                if(arr[prev_index]<arr[i]){
                    dp[i] = max(dp[i], 1 + dp[prev_index]);
                }
            }
        }
        
        int ans = -1;
        
        for(int i=0; i<=n-1; i++){
            ans = max(ans, dp[i]);
        }
        
        printLIS(arr, n);
        return ans;
    }

    
    void printLIS(vector<int> &arr, int n) {
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        
        for(int i=0; i<=n-1; i++){
            
            hash[i] = i; // initializing with current index
            
            for(int prev_index = 0; prev_index <= i-1; prev_index++){
                
                if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<=n-1; i++) {
            if(dp[i] > ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex) { // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        
        // reverse the array 
        reverse(temp.begin(), temp.end());
        
        cout << "The subsequence elements are ";
        
        for(int i=0; i<temp.size(); i++){
            cout << temp[i] << " ";
        }

        cout << endl;
    }
    

    int lengthOfLIS(vector<int>& nums) {
        return fLinear(nums, nums.size());
    }
};