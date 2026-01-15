class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mh = 1, mv = 1, curr = 1;

        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) curr++;
            else curr = 1;
            mh = max(mh, curr);
        }

        curr = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) curr++;
            else curr = 1;
            mv = max(mv, curr);
        }
        
        return min(mh + 1, mv + 1) * min(mh + 1, mv + 1);
    }
};