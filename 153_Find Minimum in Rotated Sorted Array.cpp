class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t lt = 0, rt = nums.size()-1;
        while(lt < rt) {
            int mid= lt + (rt - lt)/2;
            if(nums[mid] <= nums[rt]) rt = mid;
            else lt = mid+1;
        }
        return nums[lt];
    }
};
