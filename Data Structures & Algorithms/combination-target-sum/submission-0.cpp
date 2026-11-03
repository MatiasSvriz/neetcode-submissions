class Solution {
public:

    void dfs(vector<int>& nums, int indice, int restante, vector<int>& actual,
                    vector<vector<int>>& resultado){

        if(restante == 0){
            resultado.push_back(actual);
            return;
        }

        if(restante < 0 || indice == nums.size()){
            return;
        }

        actual.push_back(nums[indice]);

        dfs(nums, indice, restante - nums[indice], actual, resultado);

        actual.pop_back();

        dfs(nums, indice + 1, restante, actual, resultado);

    }
        

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> resultado;
        vector<int> actual;

        dfs(nums, 0, target, actual, resultado);

        return resultado;

    }
};
