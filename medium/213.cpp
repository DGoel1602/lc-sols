class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int ret;

        int dp[100];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i<nums.size()-1; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        ret = dp[nums.size()-2];

        memset(dp, 0, sizeof(dp));
        dp[1] = nums[1];
        for(int i = 2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        ret = max(ret, dp[nums.size()-1]);

        return ret;
    }
};