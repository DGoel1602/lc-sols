class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;


        queue<pair<int, int>> q;
        q.push({0, 0});
        int cur_furthest = 0;
        while(!q.empty()){
            auto t = q.front(); q.pop();

            int req = cur_furthest-t.first;
            cur_furthest = max(cur_furthest, nums[t.first] + t.first);
            for(int i = nums[t.first]; i>req; i--){
                if(i + t.first < n) {
                    if(i + t.first == n-1) return t.second+1;
                    q.push({i + t.first, t.second + 1});
                }
            }
        }    
        return -1;    
    }
};