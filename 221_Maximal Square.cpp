class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int> > dp(2, vector<int>(matrix[0].size(), 0));
        vector<int> up(matrix[0].size(), 0);
        int cur = 0, prev=1, ans = 0;
        for(int i=0; i<matrix.size(); i++) {
            int lt = 0;
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == '1') {
                    dp[cur][j] = min(dp[prev][j-1], lt);
                    dp[cur][j] = min(dp[cur][j], up[j]);
                    dp[cur][j] ++;
                    lt++;
                    up[j]++;
                    if(dp[cur][j] > ans) {
                        ans = dp[cur][j];
                    }
                }
                else {
                    dp[cur][j] = lt = up[j] = 0;
                }

            }
            prev = cur;
            cur = cur ^ 0x1;
        }

        return ans * ans;
    }
};
