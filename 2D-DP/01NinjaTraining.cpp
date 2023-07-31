// Similar to AtCoder vacation -> https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {

	if(dp[day][last] != -1) return dp[day][last];

    //base case
    //day 0, pick the task which has max. points and is not the same as
    // day 1's task
    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i<3; i++) {
            if(i != last) {
                maxi = max(maxi, points[0][i]);
            }
        }

        return dp[day][last] = maxi;
    }

    //recursive case
    int maxi = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + f(day - 1, task, points, dp);
            //do the task'th task on day'th day, and now figure out path for 
            //preceding days
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    // vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // //You will do 4th task i.e. no task on last day, work backwards
    // return f(n-1, 3, points, dp); //not passsing n-2 because we still have to decide
                            //for this day!!!


    //ITERATIVE DP
    vector<vector<int>> dp(n, vector<int>(4));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);

    dp[0][3] = max(dp[0][0], max(dp[0][1], dp[0][2]));

    for(int day = 1; day < n; day++) {


        for(int last = 0; last < 4; last++) {

            //if day = 3, we have this
            /*
                last = 0
                did 0th task on 4th day
                on day 3 we can do 1 & 2. We do both of them and fetch the answer

                last = 1
                did 1st task on 4th day
                on day 3 we can do 0 & 2, we do both of them and fetch the values

                last = 2
                did 2nd task on 4th day
                on day 3 we can do 0 & 1, do both and get ans.

                last = 3
                Here, we aren't deciding what to do on 4th day. So, on day 3 we have
                full freedom to do whatever task we want as long as the final sum is greatest
            */

            int maxi = 0;
            
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }

            dp[day][last] = maxi;
        }
    }

    return dp[n-1][3];
    //we are returning this so that in the loop we have full freedom to do 0th task ->
    //get max points; do 1st task, get max points; do 2nd task, get max points.
    //So we can take max of these answers and return it. 

    //dp[n-1][3] means we haven't done anything on the (n+1)th day, so we have full freedom here


    //SPACE-OPTIMIZED
    vector<int> prev(4);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day<n; day++) {
        vector<int> temp(4);
        for(int last = 0; last < 4; last++) {

            for(int task = 0; task < 3; task++) {

                if(task != last)
                temp[last] = max(temp[last], points[day][task] + prev[task]);
            }
        }
        prev = temp; //so that temp can serve as prev for the next iteration
    }

    return prev[3];
}

int main() {
	vector<vector<int>> points = {{10, 40, 70},
								  {20, 50, 80},
								  {30, 60, 90}};

    int n = points.size();

    cout << ninjaTraining(n, points);
}