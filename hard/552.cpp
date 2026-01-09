class Solution {
public:
    long long MOD = 1e9 + 7;

    int df(bool usedAbsent, bool l2, bool l, int n, vector<vector<vector<vector<int>>>> &dp){
        if(n == 0) return 1;
        
        if (dp[n][usedAbsent][l2][l] != -1) return dp[n][usedAbsent][l2][l];

        long long t = 0;
        if(!usedAbsent) t += df(true, l, 0, n-1, dp);
        t += df(usedAbsent, l, 0, n-1, dp);
        if(!(l2 && l)) t += df(usedAbsent, l, 1, n-1, dp);

        dp[n][usedAbsent][l2][l] = t % MOD;
        return t % MOD;
    }

    int checkRecord(int n) {
        long long t = 0;

        vector<vector<vector<vector<int>>>> dp = vector<vector<vector<vector<int>>>>(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));

        if(n == 1) return 3;

        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i == 0 && j == 0) continue;
                t = (t + df(i == 0 || j == 0, i == 1, j == 1, n-2, dp)) % MOD;
            }
        }        
        return t;
    }
};

