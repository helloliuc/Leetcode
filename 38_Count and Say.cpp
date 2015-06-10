class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for(int i=2; i<=n; i++) {
            string prev = cur;
            stringstream ss;
            for(int j=0, cnt=0; j<prev.length(); j++) {
                cnt++;
                if(prev[j] != prev[j+1]) {
                    ss<<cnt<<prev[j];
                    cnt = 0;
                }
            }
            cur = ss.str();
        }
        return cur;
    }
};
