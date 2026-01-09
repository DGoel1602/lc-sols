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
    bool valBst(TreeNode* root, long long ma, long long mi){
        if(root == nullptr) return true;
        if(root->val >= ma || root->val <= mi) return false;
        return valBst(root->left, min(ma, (long long)root->val), mi) && valBst(root->right, ma, max(mi, (long long)root->val));
    }

    bool isValidBST(TreeNode* root) {
        return valBst(root, 1e18, -1e18);         
    }
};