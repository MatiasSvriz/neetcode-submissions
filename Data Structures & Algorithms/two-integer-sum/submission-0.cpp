class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){

            int num = nums[i];

            int complement = target - num;

            if(seen.count(complement) > 0){
                return {seen[complement], i};
            }

            seen[num] = i;
        }

        return {};
    }
};

