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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int>temp;
            for(int i = 0; i < sz; i++) {
                TreeNode* pp = q.front();
                q.pop();
                temp.push_back(pp -> val);
                if(pp -> left) q.push(pp -> left);
                if(pp -> right) q.push(pp -> right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
