//without map, faster
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[255];
        memset(pos, -1,sizeof(pos));
        int ret = 0;

        for(int lt = 0, rt = 0; rt < s.length(); rt++) {
            if(pos[s[rt]] >= lt) {
                lt = pos[s[rt]] + 1;
            }
            pos[s[rt]] = rt;
            ret = max(ret, rt - lt + 1);
        }
        return ret;
    }
};
