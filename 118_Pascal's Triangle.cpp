class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret(numRows, vector<int>());
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<=i; j++) {
                ret[i].push_back(j == 0 ? 1 : j == i ? 1 : ret[i-1][j-1] + ret[i-1][j]);
            }
        }
        return ret;
    }
};
