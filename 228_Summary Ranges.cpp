class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int stpos = 0;
        vector<string> ret;
        for(int i = 0; i < nums.size(); i++) {
            if(i == nums.size() - 1 || nums[i] + 1 != nums[i + 1]) {
                if(nums[stpos] == nums[i]) {
                    ret.push_back(std::to_string(nums[i]));
                }
                else {
                    ret.push_back(std::to_string(nums[stpos]) + "->" + std::to_string(nums[i]));
                }
                stpos = i + 1;
            }
        }
        return ret;
    }
};
