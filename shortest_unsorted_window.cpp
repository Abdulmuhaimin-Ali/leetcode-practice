class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;
        int n = arr.size();
        

        // monotic increasing from start to end
        while(start < end){
            if(arr[start] <= arr[start+1]){
                start++;
            }else{
                break;
            }
        }

        // monotonic decreasing from end to start
        while(end > 0){
            if(arr[end] >= arr[end-1]){
                end--;
            }else{
                break;
            }
        }

        if(start == n-1) return 0;
        
        int result = min(n - start - 1, end);

        int i = 0, j = end;

        while(i <= start && j < n){
            if(arr[i] <= arr[j]){
                result = min(result, j - i -1);
                i++;
            }else{
                j++;
            }
        }
        return result; 
    }
};