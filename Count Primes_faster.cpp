class Solution {
public:
    int countPrimes(int n) {
        bool flag[n];
        memset(flag, 0, sizeof(flag));
        int ans = n-2<0?0:n-2;
        int bound = sqrt(n);
        for(int i=2; i<=bound; i++) {
            if(!flag[i]) {
                for(int j=i*i; j<n; j+=i) {
                    if(!flag[j]) {
                        ans--;
                        flag[j] = true;
                    }
                }
            }
        }
        return ans;
    }
};
