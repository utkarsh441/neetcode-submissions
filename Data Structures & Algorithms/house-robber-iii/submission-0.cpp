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
    unordered_map<TreeNode*, unordered_map<int, int>>dp;
    int helper(TreeNode* root, int flag) {
        if(!root) return 0;
        // int ans = 0;
        if(dp[root][flag] != -1) return dp[root][flag];
        int take = 0, nottake = 0;
        if(flag) take = root -> val + helper(root -> left, 0) + helper(root -> right, 0);
        nottake = helper(root -> left, 1) + helper(root -> right, 1);
        return dp[root][flag] = max(take, nottake);
    }
    void traverse(TreeNode* root) {
        if(!root) return;
        traverse(root -> left);
        dp[root][0] = -1;
        dp[root][1] = -1;
        traverse(root -> right);
    }
    int rob(TreeNode* root) {
        traverse(root);
        return helper(root, 1);
    }
};