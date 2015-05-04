class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> pos;
        int ret = 0;

        for(int lt = 0, rt = 0; rt < s.length(); rt++) {
            if(pos.find(s[rt]) != pos.end() && pos[s[rt]] >= lt) {
                lt = pos[s[rt]] + 1;
            }
            pos[s[rt]] = rt;
            ret = max(ret, rt - lt + 1);
        }
        return ret;
    }
};

