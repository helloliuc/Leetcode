class Solution {
public:
    int my_lowerBound(vector<int> &nums, int target) {
        int lt = 0, rt = nums.size();
        while(lt < rt) {
            int mid = lt + (rt - lt) / 2;
            if(nums[mid] < target) lt = mid + 1;
            else rt = mid;
        }
        return lt;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int pos = my_lowerBound(nums, target);
        if(pos == nums.size() || nums[pos] != target) return ans;
        ans[0] = pos;
        pos = my_lowerBound(nums, target+1);
        ans[1] = pos - 1;
        return ans;
    }
};
