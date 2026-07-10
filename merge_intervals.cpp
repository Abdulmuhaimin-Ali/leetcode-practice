class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for(int i = 0; i < intervals.size(); i++){

            int start = intervals[i][0];
            int end = intervals[i][1];

            // skipped merged intervals
            if(!result.empty() && result.back()[1] >= end) continue;


            for(int j = i+1; j < intervals.size(); j++){
                if(intervals[j][0] > end){
                    break;
                }

                end = max(end, intervals[j][1]);
            }
            result.push_back({start, end});
        }
        return result;
    }
};