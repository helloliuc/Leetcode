class Solution {
public:
    int climbStairs(int n) {
        int prev1=1, prev2=0, cur;
        for(int i=1; i<=n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;  prev1 = cur;
        }
        return cur;
    }
};
