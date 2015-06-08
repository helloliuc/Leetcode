class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lt = 0, rt = nums.size() -1;
        while(lt <= rt) {
            while(lt < nums.size() && nums[lt] != val) { lt++; }
            while(rt >= 0 && nums[rt] == val) { rt--; }
            if(lt < rt) {
                swap(nums[lt], nums[rt]);
                lt++;
                rt--;
            }
        }
        return rt < 0 ? 0 : rt+1;
    }
};
