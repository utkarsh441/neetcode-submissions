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
    unordered_map<int, int>mpp;
    int idx;
    TreeNode* helper(int l, int r, vector<int>&preorder, vector<int>&inorder) {
        // if(l > r) return nullptr;
        int k = preorder[idx++];
        int pp = mpp[k];
        TreeNode* newnode = new TreeNode(k);

        newnode ->left = nullptr;

        if(l <= pp - 1){
            // ++idx;
            newnode -> left = helper(l, pp - 1, preorder, inorder);
        }
        newnode -> right = nullptr;
        if(r >= pp + 1){
            // ++idx;
            newnode -> right = helper(pp + 1, r, preorder, inorder);
        }
        return newnode;
    }   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // idx = inorder.size() - 1;
        idx = 0;
        int n = inorder.size();
        for(int i = 0; i < inorder.size(); i++) mpp[inorder[i]] = i;
        TreeNode* root = helper(0, n - 1, preorder, inorder);
        return root;
    }
};
