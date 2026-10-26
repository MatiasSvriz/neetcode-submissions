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

    int mesureDepth(TreeNode* root, int depth, int maxDepth){

        if(root == nullptr){
            return depth;
        }

        if(depth > maxDepth){
            maxDepth = depth;
        }

        int leftDepth = mesureDepth(root->left, depth + 1, maxDepth);
        int rightDepth = mesureDepth(root->right, depth + 1, maxDepth);

        return max(leftDepth,rightDepth);

    }

    int maxDepth(TreeNode* root) {
        return mesureDepth(root, 0, 0);
    }
};
