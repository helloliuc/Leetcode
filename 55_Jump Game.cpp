class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdis = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maxdis >= i) {
                maxdis = max(maxdis, i + nums[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};
