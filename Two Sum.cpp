class Solution {
    public:
        unordered_map<int, int> mp;
        vector<int> twoSum(vector<int>& nums, int target) {
            for(int i=0; i<nums.size(); i++) {
                if(mp.find(nums[i]) != mp.end()) {
                    vector<int> ret;
                    ret.push_back(mp[nums[i]]);
                    ret.push_back(i+1);
                    return ret;
                }
                mp.insert(make_pair(target - nums[i], i+1));
            }
        }
};
