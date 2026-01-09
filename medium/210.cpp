class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>(0));
        for(vector<int> req: prerequisites){
            indegrees[req[0]]++;
            adj[req[1]].push_back(req[0]);
        }        

        queue<int> zeros;
        for(int i = 0; i<numCourses; i++){
            if(indegrees[i] == 0) zeros.push(i);
        }

        vector<int> top;
        top.reserve(numCourses);
        
        while(!zeros.empty()){
            int t = zeros.front(); zeros.pop();
            top.push_back(t);

            for(int v: adj[t]){
                indegrees[v]--;
                if(indegrees[v] == 0) zeros.push(v);
            }
        }

        if(top.size() < numCourses) return {};

        return top;
    }
};