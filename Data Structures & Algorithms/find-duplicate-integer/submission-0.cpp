class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> seen;

        for(int num : nums){

            if(seen.count(num) > 0){
                return num;
            }

            seen[num] += 1;

        }

        return -1;

    }
};
