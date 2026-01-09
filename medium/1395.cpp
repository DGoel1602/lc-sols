class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<vector<int>> higher(rating.size());
        vector<vector<int>> lower(rating.size());
        for(int i = 0; i < rating.size(); i++){
            for(int j = i + 1; j<rating.size(); j++){
                if(rating[j] > rating[i]) higher[i].push_back(j);
                if(rating[j] < rating[i]) lower[i].push_back(j);
            }
        }
        int t = 0;
        for(int i = 0; i<rating.size(); i++){
            for(int v: higher[i]){
                t += higher[v].size();
            }
            for(int v: lower[i]){
                t += lower[v].size();
            }
        }

        return t;
    }
};