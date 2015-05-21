class Solution {
public:
    string convertToTitle(int n) {
        vector<char> ans;
        while(n!=0) {
            ans.push_back('A' + (n-1)%26);
            n = (n-1)/26;
        }
        return string(ans.rbegin(), ans.rend());
    }
};
