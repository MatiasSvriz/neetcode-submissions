class Solution {
public:

    vector<string> keyboard = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void dfs(string& digits, int index, string& actual, 
            vector<string>& output){

        if(index == digits.size()){
            output.push_back(actual);
            return;
        }

        string actualLetters = keyboard[digits[index] - '0'];

        for(char letter : actualLetters){

            actual.push_back(letter);

            dfs(digits, index + 1, actual, output);

            actual.pop_back();

        }

    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> output;
        string actual = "";

        if(digits.empty()){

            return output;

        }

        dfs(digits, 0, actual, output);

        return output;

    }
};
