/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void dfs(TreeNode* root, int nivel, vector<vector<int>>& resultado){

        if(root == nullptr){
            return;
        }

        if(nivel == resultado.size()){
            resultado.push_back({});
        }

        resultado[nivel].push_back(root->val);

        dfs(root->left, nivel + 1, resultado);
        dfs(root->right, nivel + 1, resultado);

    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultado;

        dfs(root, 0, resultado);

        return resultado;
    }
};
