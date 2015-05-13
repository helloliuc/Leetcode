class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i=30; i>=0; i--) {
            if(n - m <= (1<<i) && (n & (1<<i)) && (m & (1<<i))) {
                ans |= 1<<i;
            }
        }
        return ans;
    }
};
