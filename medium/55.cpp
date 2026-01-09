class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for(int i = 0; i<=m && i<nums.size(); i++){
            if(i == nums.size()-1) return true;
            m = max(m, i + nums[i]);
        }
        return false;        
    }
};