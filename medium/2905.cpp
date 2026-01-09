class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        pair<int, int> most = {nums[0], 0};
        pair<int, int> least = {nums[0], 0};

        for(int i = indexDifference; i<nums.size(); i++){
            int mir = i - indexDifference;
            if(most.first < nums[mir]) most = {nums[mir], mir};
            if(least.first > nums[mir]) least = {nums[mir], mir};
            
            if(most.first >= nums[i] + valueDifference) return {i, most.second};
            if(least.first <= nums[i] - valueDifference) return {i, least.second};
        }
        return {-1, -1};
    }
};