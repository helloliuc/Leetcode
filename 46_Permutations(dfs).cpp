class Solution {
public:
    void dfs(int pos, vector<int> &nums, vector<vector<int> > &ans) {
        if(pos >= nums.size()) {
            ans.push_back(nums);
            return ;
        }
        for(int i=pos; i<nums.size(); i++) {
            swap(nums[pos], nums[i]);
            dfs(pos+1, nums, ans);
            swap(nums[pos], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        dfs(0, nums, ans);
        return ans;
    }
};
