bool cmp(string &a, string &b) {
    return a + b > b + a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vecstr;
        for(auto it = nums.begin(); it != nums.end(); it++) {
            vecstr.push_back(std::to_string(*it));
        }
        sort(vecstr.begin(), vecstr.end(), cmp);
        string ans = "";
        if(*vecstr.begin() == "0") return "0";
        for(auto it = vecstr.begin(); it != vecstr.end(); it++) ans += *it;
        return ans;
    }
};
