class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> busStops;
        for(int i = 0; i<routes.size(); i++) {
            for(int pos: routes[i]) {
                busStops[pos].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        vector<int> visited(501, 0);
        unordered_set<int> visitedStops;
        q.push({source, 0});


        while(!q.empty()){
            auto top = q.front(); q.pop();

            if (top.first == target) return top.second;

            for(int bus: busStops[top.first]){
                if(visited[bus]) continue;
                visited[bus] = 1;
                
                for(int position: routes[bus]) {
                    if(visitedStops.count(position)) continue;
                    visitedStops.insert(position);
                    q.push({position, top.second + 1});
                }
            }
        }


        return -1;       
    }

};