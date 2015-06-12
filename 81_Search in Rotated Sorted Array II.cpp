class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if(nums.size() == 0) return -1;
        int lt = 0, rt = nums.size()-1;
        while(lt <= rt) {
            int mid = (lt + rt) /2;
            if(target == nums[mid])  return true;
            if(nums[mid] > nums[lt]) {
                if(target > nums[mid]) {
                    lt = mid + 1;
                }
                else {
                    if(target >= nums[lt]) {
                        rt = mid - 1;
                    }
                    else {
                        lt = mid + 1;
                    }
                }
            }
            else if(nums[mid] < nums[lt]) {
                if(target < nums[mid]) {
                    rt = mid - 1;
                }
                else {
                    if(target <= nums[rt]) {
                        lt = mid + 1;
                    }
                    else {
                        rt = mid - 1;
                    }
                }
            }
            else {
                lt++;
            }
        }
        
        return false;
    }
};
