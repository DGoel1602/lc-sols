class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const long long base = 128;
        const long long MOD = 1e9+1;
        unordered_map<long long, int> m;
        vector<vector<string>> ret;
        
        for(string str: strs){
            int counts[26] = {0};
            for(char c: str) counts[c - 'a']++;
            long long res = 0;
            for(int i = 0; i<26; i++) {
                res *= base;
                res = (res + counts[i]) % MOD;
            }
            if(!m.count(res)) {
                m.insert({res, m.size()});
                ret.push_back({});
            }
            ret[m[res]].emplace_back(str);
        }        

        return ret;
    }
};