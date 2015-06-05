class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)  return 0.0;
        long long N = n;
        N = N < 0 ? -N : N;
        double factor = x;
        double ret = 1.0;
        while(N) {
            if(N & 0x1) {
                ret = ret * factor;
            }
            factor = factor * factor;
            N >>= 1;
        }
        return n < 0 ? 1 / ret : ret;
    }
};
