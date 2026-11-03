
class Solution {
public:

    void dfs(vector<int>& nums, int indice, vector<int>& actual,
                                        vector<vector<int>>& resultado) {

        if(indice == nums.size()){
            resultado.push_back(actual);
            return;
        }

        dfs(nums, indice + 1, actual, resultado);

        actual.push_back(nums[indice]);

        dfs(nums, indice + 1, actual, resultado);

        // Deshacemos la última decisión
        actual.pop_back();

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> resultado;
        vector<int> actual;

        dfs(nums, 0, actual, resultado);

        return resultado;
    }
};
