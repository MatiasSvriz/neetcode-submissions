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

    // Devuelve la altura del subárbol.
    // Si encuentra un desequilibrio, devuelve -1.
    int dfs(TreeNode* root){

        // Un arbol vacío devuelve cero.
        if(root == nullptr){
            return 0;
        }

        // Calculamos recursivamente la altura de ambos subárboles.
        int left = dfs(root->left);
        int right = dfs(root->right);

        // Si algún subárbol está desequilibrado, propagamos el -1.
        if(left == -1 || right == -1){
            return -1;
        }

        // Si la diferencia de alturas es > 1, el árbol está desequilibrado.
        if(abs(left - right) > 1){
            return -1;
        }

        // Si está equilibrado, devolvemos 1 + la altura del hijo más alto.
        return 1 + max(left, right);

    }

    bool isBalanced(TreeNode* root) {
        
        if(dfs(root) != -1){
            return true;
        }else{
            return false;
        }

    }
};
