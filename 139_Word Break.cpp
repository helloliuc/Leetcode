class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> flag(s.length()+1, false);
        flag[0] = true;
        for(int i = 0; i < s.length(); i++) {
            if(flag[i]) {
                for(auto it = wordDict.begin(); it != wordDict.end(); it++) {
                    if(s.substr(i, (*it).length()) == *it) {
                        flag[i + (*it).length()] = true;
                        if(flag[s.length()] == true) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
