class Solution {
public:
    vector<int> sums;
    void df(TreeNode* root) {
        int t = root->val;
        if(root->left != nullptr) {
            df(root->left);
            t += sums[sums.size()-1];
        }
        if(root->right != nullptr) {
            df(root->right);
            t += sums[sums.size()-1];
        }
        sums.push_back(t);
    }

    int maxProduct(TreeNode* root) {
        df(root);
        int total = sums[sums.size()-1];
        long long m = 0;
        for(int sum: sums) m = max(m, (long long)sum * (total - sum));
        return (m % (long long)(1e9 + 7));
    }
};