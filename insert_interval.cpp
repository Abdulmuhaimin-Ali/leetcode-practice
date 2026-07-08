class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // add all intervals that don't overlap newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i++]);
        }

        // now merge all overlapping intervals with newInterval
        // everything to the right could be merged into newInterval so wee keep looping as long as the start
        // of our next interval is smaller then newIntervals
        // end

        int start = newInterval[0], end = newInterval[1];
        while(i < n && intervals[i][0] <= end){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        
        res.push_back({start, end});

        // finished merging all possible newIntervals overlapps

        // all that is left now is the remaining intervals lets add those

        while(i < n){
            res.push_back(intervals[i++]);
        }
        return res;
    }
};