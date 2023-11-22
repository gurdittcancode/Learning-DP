class Solution {
public:

    int largestRectangle(vector<int>& histo) {
        int n = histo.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<=n; i++) {
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        vector<int> heights(n, 0);

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                //include this in the existing bar
                else heights[j] = 0;
                //starting with 0, reduce this bar to 0
            }
            int area = largestRectangle(heights);
            ans = max(ans, area);
        }

        return ans;
    }

};