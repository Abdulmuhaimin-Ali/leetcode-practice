// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

// basically we need to return the number of triplets that are less then the target sum.

/* if we reach a sum where the sum of i, j, k is less than target. then we know that 
any previouis k would generate a sum less then target. so we're able to increase count
 by end - start not adding 1 becuase we don't want to double count j.

       i  j     k    target = 3
       count+= k - j = 3 - 1 = 2 correct!
 ex. [-1, 0, 2, 3]
       0   1  2  3

*/


int triplet_with_smaller_sum(vector<int> nums, int target){
    int size = nums.size();
    int count = 0;

    for(int i = 0; i < size; i++){
        
        int start = i+1;
        int end = size-1;

        while(start < end){
            if(nums[i] + nums[start] + nums[end] < target){
                count += end - start;
                start++;
            }else{
                end--;
            }
        }
    }
    return count;

}


int main() {
	
    vector<int> test1 = {-1, 0, 2, 3};
    int trip_count = triplet_with_smaller_sum(test1, 3);

	cout << "The triplet count is " << trip_count <<  "\n";
}
