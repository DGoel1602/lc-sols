/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        int s = min(p->val, q->val);
        int b = max(p->val, q->val);
        while(true) {
            if(s < curr->val && b < curr->val){
                if(curr->left == nullptr) break;
                curr = curr->left;
                continue;
            } else if(s > curr->val && b > curr->val){
                if(curr->right == nullptr) break;
                curr = curr->right;
                continue;
            } else break;
        }
        return curr; 
    }
};