class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> m;
        for(vector<string> access: access_times){
            int hour = stoi(string(1, access[1][0]) + string(1, access[1][1])) * 60;
            int min = stoi(string(1, access[1][2]) + string(1, access[1][3]));
            m[access[0]].push_back(hour + min);
        }

        vector<string> high_access;
        for(auto &it: m){
            vector<int> acs = it.second;
            sort(acs.begin(), acs.end());
            for(int i = 1; i < acs.size() - 1; i++){
                if(acs[i-1] + 60 > acs[i+1]){
                    high_access.push_back(it.first);
                    break;
                }
            }
        }

        return high_access;
    }
};