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
    int ans = -1e9;
    int hehe(TreeNode* root) {
        if(!root) return 0;
        int l = hehe(root -> left);
        int r = hehe(root -> right);
        ans = max(ans, l + r + root -> val);
        return max(0, root -> val + max(l, r));
    }
    int maxPathSum(TreeNode* root) {
        int pp = hehe(root);
        return ans; 
    }
};
