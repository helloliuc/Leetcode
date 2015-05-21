class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<bool> vis(nums.size(), false);
        for(int i=0; i<k; i++) {
            if(vis[i])  continue;
            int prev = nums[i];
            for(int j=(i+k)%nums.size(); !vis[j]; j=(j+k)%nums.size()) {
                vis[j] = true;
                swap(prev, nums[j]);
            }
        }
    }
};
