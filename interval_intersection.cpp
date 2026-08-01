class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        if(firstList.size() == 0){
            return {};
        }

        int f_size = firstList.size();
        int s_size = secondList.size();

        int first = 0;
        int second = 0;

        vector<vector<int>> intersections;

        while(first < f_size && second < s_size){
            // find intersections
            // check overlap first
            
            int start = max(firstList[first][0], secondList[second][0]);
            int end = min(firstList[first][1], secondList[second][1]);
            // if valid overlap add.
            if(start <= end || start <= end){
                intersections.push_back({start, end});
            }

            if(firstList[first][1] > secondList[second][1]){
                second++;
            }else{
                first++;
            }
        }
        return intersections;
    }
};