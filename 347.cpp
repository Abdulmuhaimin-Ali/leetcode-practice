class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            vector<int> res;
            unordered_map<int, int> mp;
            for(int i =0; i < nums.size(); i++){
                mp[nums[i]]++;
            }
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap; 
    
    
            for(const auto& num : mp){
                maxHeap.push({num.second, num.first});
            }
    
            auto it = maxHeap;
            for( int i = 0; i < k; i++){
                res.push_back({maxHeap.top().second});
                maxHeap.pop();
            }
    
    
            return res;
        }
    };