class Solution {
public:

    void dfs(vector<int>& candidates, int indice, int restante,
            vector<int>& actual, vector<vector<int>>& resultado){

        if(restante == 0){
            resultado.push_back(actual);
            return;
        }

        if(restante < 0 || indice == candidates.size()){
            return;
        }

        actual.push_back(candidates[indice]);

        dfs(candidates, indice + 1, restante - candidates[indice],
                actual, resultado);

        actual.pop_back();

        int siguienteIndice = indice + 1;

        while(siguienteIndice < candidates.size() 
                && candidates[siguienteIndice] == candidates[indice]){

            siguienteIndice += 1;

        }

        dfs(candidates, siguienteIndice, restante, actual, resultado);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> resultado;
        vector<int> actual;

        dfs(candidates, 0, target, actual, resultado);

        return resultado;

    }
};
