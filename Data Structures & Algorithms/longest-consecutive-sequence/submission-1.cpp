class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> seen;

        int longest = 0;

        for(int num : nums){

            seen.insert(num);

        }

        for(int num : seen){

            if(seen.count(num - 1) == 0){

                int count = 1;
                int currentNum = num; // starter

                while(seen.count(currentNum + 1) > 0){
                    count += 1;
                    currentNum += 1;
                }

                longest = max(count, longest);

            }

        }

        return longest;

    }
};
