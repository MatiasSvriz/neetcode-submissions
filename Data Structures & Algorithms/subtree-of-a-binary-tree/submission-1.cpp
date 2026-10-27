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

    bool isSameTree(TreeNode* p, TreeNode* q){

        if(p == nullptr && q == nullptr){
            return true;
        }

        if(p == nullptr || q == nullptr){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool leftSame = isSameTree(p->left, q->left);
        bool rightSame = isSameTree(p->right, q->right);

        return leftSame && rightSame;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == nullptr){
            return true;
        }

        // Si ya no queda donde buscar.
        if(root == nullptr){
            return false;
        }

        // Si son exactamente el mismo arbol.
        if(isSameTree(root, subRoot)){
            return true;
        }

        bool foundInTheLeft = isSubtree(root->left, subRoot);
        bool foundInTheRight = isSubtree(root->right, subRoot);

        return foundInTheLeft || foundInTheRight;

    }
};
