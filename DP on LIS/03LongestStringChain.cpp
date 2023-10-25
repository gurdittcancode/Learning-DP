class Solution {
public:

    bool compare(string &s, string &t) {
        //we are assuming that s is the greater guy
        if(s.size() != t.size() + 1) return false; 
        int first = 0;
        int second = 0;

        while(first < s.size()) {
            if(s[first] == t[second]) {
                first++; second++;
            }
            else first++;
        }

        if(first == s.size() && second == t.size()) return true;

        return false;
    }

    static bool comp(string &s, string &t) {
        return s.size() < t.size();
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end(), comp);

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i<n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(compare(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]) 
                    dp[i] = 1 + dp[prev];
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};