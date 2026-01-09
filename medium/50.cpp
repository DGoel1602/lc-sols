class Solution {
public:
    double myPow(double x, int n1) {
        if(n1 < 0) x = 1/x;
        long long n = abs((long long)n1);
        double res = 1;
        while(n > 0){
            if(n & 1 == 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;        
    }
};