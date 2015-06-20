class Solution {
public:
    string getPermutation(int n, int k) {
        int factor = 1;
        for(int i = 1; i <= n; i++) {
            factor = factor * i;
        }
        if(factor < k) return "";
        k--;
        vector<char> res(n, 0);
        vector<bool> flag(10, false);
        for(int i = 0; i < n; i++) {
            factor = factor / (n - i);
            int t = k / factor;
            int cnt = -1;
            for(int j = 1; j < 10; j++) {
                if(flag[j] == false) {
                    cnt++;
                }
                if(cnt == t) {
                    flag[j] = true;
                    res[i] = j + '0';
                    break;
                }
            }
            k = k % factor;
        }
        return string(res.begin(), res.end());
    }
};
