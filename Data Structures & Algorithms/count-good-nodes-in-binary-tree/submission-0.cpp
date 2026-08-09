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
    int helper(TreeNode* root, int maxi) {
        if(!root) return 0;
        int ans = (root -> val >= maxi) ? 1 : 0;
        int newmaxi = max(maxi, root -> val);
        ans += helper(root -> left, newmaxi);
        ans += helper(root -> right, newmaxi);
        return ans; 
    }
    int goodNodes(TreeNode* root) {
        int ans = helper(root, -1e9);
        return ans;
    }
};
