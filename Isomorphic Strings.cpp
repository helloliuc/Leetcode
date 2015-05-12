class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        map<char, char> rmp;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp.insert(make_pair(s[i], t[i]));
            }
            else if(mp[s[i]] != t[i]) {
                return false;
            }
            if(rmp.find(t[i]) == rmp.end()) {
                rmp.insert(make_pair(t[i], s[i]));
            }
            else if(rmp[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
