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

    void dfs(TreeNode* root, int& buenos, int maximo){

        if(root == nullptr){
            return;
        }

        if(root->val >= maximo){
            buenos += 1;
        }

        maximo = max(maximo, root->val);

        dfs(root->left, buenos, maximo);
        dfs(root->right, buenos, maximo);

    }

    int goodNodes(TreeNode* root) {

        int buenos = 0;
        int maximo = root->val;

        dfs(root, buenos, maximo);

        return buenos;

    }
};
