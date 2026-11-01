
class Solution {
public:

    void dfs(vector<int>& nums,
             int indice,
             vector<int>& actual,
             vector<vector<int>>& resultado) {

        // Caso base, hemos decidido sobre todos los números.
        if (indice == nums.size()) {
            resultado.push_back(actual);
            return;
        }

        // OPCIÓN 1, No incluir el número actual.
        dfs(nums, indice + 1, actual, resultado);

        // OPCIÓN 2, Incluir el número actual.
        actual.push_back(nums[indice]);

        dfs(nums, indice + 1, actual, resultado);

        // Backtracking, deshacemos la última decisión.
        actual.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> resultado;
        vector<int> actual;

        dfs(nums, 0, actual, resultado);

        return resultado;
    }
};
