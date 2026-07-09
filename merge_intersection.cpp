class Solution {
    public:
        vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    
            if (firstList.size() == 0 || secondList.size() == 0){
                return {};
            }
            
            int first_i = 0;
            int second_i = 0;
    
            vector<vector<int>> result;
        
            while(first_i < firstList.size() && second_i < secondList.size()){
                int start = max(firstList[first_i][0], secondList[second_i][0]);
                int end = min(firstList[first_i][1], secondList[second_i][1]);
    
                if(start <= end){
                    result.push_back({start, end});
                }
    
                if(firstList[first_i][1] < secondList[second_i][1]){
                    first_i++;
                }else{
                    second_i++;
                }
            }
            return result;
        }
    };