class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> frequency;

        for(int num : nums){

            frequency[num]++;

        }

        vector<pair<int, int>> orderedFrequency;

        for(auto& [number, count] : frequency){
            orderedFrequency.push_back({count, number});
        } 

        // When using pairs, we sort by the first value
        // in this case, by frequency
        sort(orderedFrequency.rbegin(), orderedFrequency.rend());

        vector<int> solution;

        for(int i = 0; i < k; i++){
            solution.push_back(orderedFrequency[i].second);
        }

        return solution;


    }
};
