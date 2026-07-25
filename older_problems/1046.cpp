// sort and erase implementation for small amount of data
// Time complexity: O(n^2)
class Solution {
    private:
    priority_queue<int> max_ordered_nums;
public:

    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size() > 1){
            sort(stones.begin(), stones.end(), greater<int>());
            int first = stones[0]; stones.erase(stones.begin());

            int second = stones[0]; stones.erase(stones.begin());

            if(first != second){
                int result = first - second;
                stones.push_back(result);
            }
        }
        
        return stones.empty() ? 0 : stones[0];
    }
};

// Heap implementation for large amount of data
// Time complexity: O(nlogn)
class Solution {
    private:
    priority_queue<int> max_ordered_nums;
public:

    int lastStoneWeight(vector<int>& stones) {
        //edge cases:
        if(stones.size() < 2){
            return stones[0];
        }

        for(int& num: stones) max_ordered_nums.push(num);

        while(max_ordered_nums.size() != 1){
            int first = max_ordered_nums.top(); max_ordered_nums.pop();
            int second = max_ordered_nums.top(); max_ordered_nums.pop();

            if(first == second){
                continue;
            }else{
                int result = first - second;
                max_ordered_nums.push(result);
            }
        }
        return max_ordered_nums.top();
    }
};