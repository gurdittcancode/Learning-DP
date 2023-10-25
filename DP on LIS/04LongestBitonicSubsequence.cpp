/*
	Given an array, return the longest bitonic subsequence (find mountain in array)
	eg, arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
	ans = 6 {1, 2, 10, 5, 2, 1}


*/

#include<bits/stdc++.h>
using namespace std;

int findBitonic(vector<int> &arr) {
	int n = arr.size();

	//filling lds table
	vector<int> decDp(n, 1);
	for(int i = n-1; i>=0; i--){
        for(int prev_index = n-1; prev_index > i; prev_index--){
                
            if(arr[prev_index] < arr[i]) decDp[i] = max(decDp[i], 1 + decDp[prev_index]);
        }
    }
    
    int maxi = 0;
    //filling lis table
    vector<int> incDp(n, 1);
    for(int i = 0; i<n; i++){
        for(int prev_index = 0; prev_index<i; prev_index++){
                
            if(arr[prev_index] < arr[i]) incDp[i] = max(incDp[i], 1 + incDp[prev_index]);
        }
        maxi = max(maxi, incDp[i] + decDp[i] - 1);
    }

    return maxi;
}

int main() {

	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	cout << findBitonic(arr);

	return 0;
}