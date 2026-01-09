class Solution {
public:
    int deepest = 0;
    TreeNode* res = nullptr;

    int df(TreeNode* root, int d){
        int l = root->left != nullptr ? df(root->left, d + 1) : d;
        int r = root->right != nullptr ? df(root->right, d + 1) : d;

        if(l == r && deepest <= l) {
            deepest = l;
            res = root;
        } 
        return max(l, r);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        df(root, 0);
        return res;       
    }
};