// Maximum Sum Subarray of Size 
// Didn't have premium so had to read input my own way.


#include <bits/stdc++.h>
using namespace std;

int maximum_sum_subarray(vector<int> arr, int k){
    int max_sum = -INT_MAX;
    int window_start = 0;
    int window_sum = 0;

    for(int i = 0; i < arr.size(); i++){
        window_sum += arr[i];

        if((i - window_start + 1) >= k){
            max_sum = max(max_sum, window_sum);

            window_sum -= arr[window_start];
            window_start++;
        }
    }
    return max_sum;
}

int main() {

    int t;
    cin >> t;
    

    for(int tests = 0; tests < t; tests++){
        int n;
        cin>>n;

        vector<int> array(n, 0);
        for(int i = 0; i < n; i++){
            cin >> array[i]; 
        }

        int k;
        cin>>k;

        int ans = maximum_sum_subarray(array, k);
        cout << ans << endl;
    }
}


// test cases 
/*
2
6
2 1 5 1 3 2 3
1
-1 1
*/