class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left = 0;
        int right = 0;

        int longest = 0;
        
        unordered_set<char> subString;

        while(right < s.size()){

            while(subString.count(s[right]) > 0){

                subString.erase(s[left]);
                left ++;

            }

            subString.insert(s[right]);

            int actualLength = right - left + 1;
            longest = max(actualLength, longest);

            right ++;

        }

        return longest;

    }
};
