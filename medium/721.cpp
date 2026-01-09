struct DSU {
    vector<int> p;
    DSU(int n) {
        p.reserve(n);
        for(int i = 0; i<n; i++) p.push_back(i);
    }

    int find(int x){
        if(x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        p[b] = a;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> repr;
        DSU dsu(accounts.size());
        for(int i = 0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                auto it = repr.find(accounts[i][j]);
                if(it != repr.end()) dsu.join(it->second, i);
                else repr.insert({accounts[i][j], i});
            }
        }  

        unordered_map<int, set<string>> idxToEmails;
        for(int i = 0; i<accounts.size(); i++){
            auto &ref = idxToEmails[dsu.find(i)];
            for(int j = 1; j<accounts[i].size(); j++) {
               ref.insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ret;
        for(auto it = idxToEmails.begin(); it != idxToEmails.end(); it++) {
            ret.push_back({accounts[it->first][0]});
            for(string email: idxToEmails[it->first]) ret[ret.size()-1].push_back(email);
        }

        return ret;
    }
};