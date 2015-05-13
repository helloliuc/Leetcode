//Be Carefull, i < n
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n, true);
        int ans = 0;
        for(int i=2; i<n; i++) {
            if(flag[i]) {
                ans++;
                for(int j=i+i; j<n; j+=i) {
                    flag[j] = false;
                }
            }
        }
        return ans;
    }
};
