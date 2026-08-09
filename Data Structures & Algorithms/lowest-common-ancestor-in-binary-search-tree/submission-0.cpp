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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int curr = 0;
        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
        if(root == p || root == q) return root; 
        if(r != nullptr && l != nullptr) return root;
        if(l) {
            if(root == p || root == q) return root;
            return l;
        } 
        if(r) {
            if(root == p || root == q) return root;
            return r;
        }
        return nullptr;
    }
};
