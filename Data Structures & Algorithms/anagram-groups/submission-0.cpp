class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> groups;

        for(string word : strs){

            string orderedWord = word;

            sort(orderedWord.begin(), orderedWord.end());

            groups[orderedWord].push_back(word);

        }

        vector<vector<string>> result;

        for(auto& [orderedWord, words] : groups){

            result.push_back(words);

        }

        return result;

    }
};
