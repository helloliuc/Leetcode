class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.length() - 1;
        while(p >= 0 && s[p] == ' ') {
            p--;
        }
        if(p < 0) return 0;
        int cnt = 0;
        while(p >= 0 && s[p] != ' ') {
            p--;
            cnt++;
        }
        return cnt;
    }
};
