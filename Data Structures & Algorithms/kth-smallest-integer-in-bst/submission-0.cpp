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

    void dfs(TreeNode* root, vector<int>& orderedValues){

        if(root == nullptr){
            return;
        }

        dfs(root->left, orderedValues);

        orderedValues.push_back(root->val);

        dfs(root->right, orderedValues);

    }

    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> orderedValues;

        dfs(root, orderedValues);

        return orderedValues[k - 1];

    }
};
