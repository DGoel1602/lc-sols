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
    vector<int> sums;
    void df(TreeNode* root, int d){
        if(sums.size() == d) sums.push_back(root->val);
        else sums[d] += root->val;
        
        if(root->left != nullptr) df(root->left, d+1); 
        if(root->right != nullptr) df(root->right, d+1);
    }
    int maxLevelSum(TreeNode* root) {
        df(root, 0);
        int smallest = 0;    
        for(int i = 1; i<sums.size(); i++) if(sums[i] > sums[smallest]) smallest = i;  
        return smallest+1;
    }
};