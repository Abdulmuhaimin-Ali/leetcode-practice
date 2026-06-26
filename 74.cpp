class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int cols = matrix[0].size();
            int rows = matrix.size();
    
            int first = 0; 
            int last = (cols * rows) - 1;
            while(first <= last){
                int midpoint = (first + last) / 2;
    
    
                // locate midpoint
                int row = midpoint / cols;
                int col = midpoint % cols;
    
                if(matrix[row][col] == target){
                    return true;
                }
    
                else if(matrix[row][col] < target){
                    first = midpoint + 1;
                }else {
                    last = midpoint - 1;
                }
                
            }
    
            return false;
        }
    };