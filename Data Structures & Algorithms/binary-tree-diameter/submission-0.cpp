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

    int mesureDiameter(TreeNode* root, int& diameter){

        if(root == nullptr){
            return 0;
        }

        int leftHeight = mesureDiameter(root->left, diameter);
        int rightHeight = mesureDiameter(root->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight); 

        return 1 + max(leftHeight, rightHeight);


    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        mesureDiameter(root, diameter);
        return diameter;
    }
};
