class Solution {
public:

    void dfs(vector<string>& output, string& actual, 
            int n, int abiertos, int cerrados){

        if(actual.size() == n * 2){
            output.push_back(actual);
            return;
        }

        if(abiertos < n){

            actual.push_back('(');

            dfs(output, actual, n, abiertos + 1, cerrados);

            actual.pop_back();

        }
        
        if(cerrados < abiertos){

            actual.push_back(')');
            
            dfs(output, actual, n, abiertos, cerrados + 1);

            actual.pop_back();

        }

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> output;
        string actual = "";

        dfs(output, actual, n, 0, 0);

        return output;

    }
};
