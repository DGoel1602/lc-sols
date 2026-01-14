class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 1e9;
        double m;

        while(abs(l-r) >= 1e-5) {
            m = (l + r) / 2;
            double diff = 0;

            for(vector<int> &sq: squares) {
                int y = sq[1], len = sq[2];
                double total = (double) len * len;
                if(y <= m && y + len >= m){
                    diff += (2 * y - 2 * m) * len + total;                    
                } else if(y <= m) {
                    diff -= total;
                } else {
                    diff += total;
                }
            }

            if(diff > 0) l = m;
            else r = m;
        }  

        return m;      
    }
};