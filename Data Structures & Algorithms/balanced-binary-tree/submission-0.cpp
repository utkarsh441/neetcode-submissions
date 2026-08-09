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
    unordered_map<TreeNode*, int>dp;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int l = helper(root -> left);
        int r = helper(root -> right);
        return dp[root] = 1 + max(l, r);
    }
    bool f(TreeNode* root) {
        if(!root) return true;
        int l = 0, r = 0;
        // bool ans = true;
        if(root -> left != nullptr) l = dp[root -> left];
        if(root -> right != nullptr) r = dp[root -> right];
        if(abs(l - r) > 1) return false;
        return f(root -> left) && f(root -> right);
    }
    bool isBalanced(TreeNode* root) {
        int kk = helper(root);
        return f(root);
    }
};
