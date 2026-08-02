class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.size() == 1){
            return trips[0][0] <= capacity;
        }

        int n = trips.size();

        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

        int on_board = 0;

        
        for (auto& trip : trips){
            int passengers = trip[0], from = trip[1], to = trip[2];

            // drop any passengers that finished before or at this stop
            while(!min_heap.empty() && min_heap.top().first <= from){
                on_board -= min_heap.top().second;
                min_heap.pop();
            }


            min_heap.push({to, passengers});
            on_board += passengers;

            if(on_board > capacity) return false;

        }

        return true;
    }
};

