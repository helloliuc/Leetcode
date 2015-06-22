class Solution {
public:
    int searchBegin(vector<int> &nums, int target) {
        int lt = 0, rt = nums.size()-1; 
        while(lt < rt) {
            int mid = lt + ((rt - lt) >>1);
            if(nums[mid] >= target) {
                rt = mid;
            }
            else {
                lt = mid + 1;
            }
        }
        if(nums[lt] != target) return -1;
        return lt;
    }
    int searchEnd(vector<int> &nums, int target) {
        int lt = 0, rt = nums.size()-1;
        while(lt < rt) {
            int mid = lt + ((rt + 1 - lt)>>1);
            if(nums[mid] > target) {
                rt = mid - 1;
            }
            else {
                lt = mid;
            }
        }
        if(nums[lt] != target) return -1;
        return lt;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(searchBegin(nums, target));
        ans.push_back(searchEnd(nums, target));
        return ans;
    }
};
