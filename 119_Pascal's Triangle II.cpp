class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(1, 1);
        for(int i=1; i<=rowIndex; i++) {
            int prev = ret[0];
            for(int j=1; j<i; j++) {
                int tmp = ret[j];
                ret[j] += prev;
                prev = tmp;
            }
            ret.push_back(1);
        }
        return ret;
    }
};
