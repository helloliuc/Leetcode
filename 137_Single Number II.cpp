class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for(int i = 0; i < 32; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += (nums[j] >> i) & 0x1;
            }
            ret |= (sum % 3) << i;
        }
        return ret;
    }
};
