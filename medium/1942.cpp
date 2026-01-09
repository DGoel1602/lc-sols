class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        unordered_set<int> chairs;
        int smallest = 0;

        int start_target = times[targetFriend][0];
        sort(times.begin(), times.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ends;

        for(int i = 0; i<times.size(); i++){
            while(!ends.empty()) {
                auto t = ends.top();
                if(t.first > times[i][0]) break;

                chairs.erase(t.second);
                smallest = min(smallest, t.second);
                ends.pop();
            }

            if(times[i][0] == start_target) return smallest;

            ends.emplace(times[i][1], smallest);
            chairs.insert(smallest);
            while(chairs.count(smallest)) smallest++;
        }

        return 0;
    }
};