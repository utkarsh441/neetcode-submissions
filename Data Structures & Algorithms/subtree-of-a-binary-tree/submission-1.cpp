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
    bool check(TreeNode *p, TreeNode* q) {
        if(!p && q || (p && !q)) return false;
        if(p == q && q == nullptr) return true;
        if(p -> val != q -> val) return false;
        return check(p -> left, q -> left) && check(p -> right, q -> right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool ans = false;
        ans = check(root, subRoot);
        ans = ans || isSubtree(root -> left, subRoot);
        ans = ans || isSubtree(root -> right, subRoot);
        return ans;
    }
};
