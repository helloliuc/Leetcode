class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lt = 0, rt = nums.size();
        while(lt < rt) {
            int mid = lt + (rt - lt) / 2;
            if(nums[mid] < target) lt = mid + 1;
            else rt = mid;
        }
        return lt;
    }
};
