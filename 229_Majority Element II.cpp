class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cx = 0, cy = 0, vx = 0, vy = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != vy && cx == 0) {
                vx = nums[i];
                cx = 1;
                continue;
            }
            if(nums[i] != vx && cy == 0) {
                vy = nums[i];
                cy = 1;
                continue;
            }
            
            if(nums[i] == vx) {
                cx++;
            }
            else if(nums[i] == vy) {
                cy++;
            }
            else {
                cx--;
                cy--;
            }
        }
        vector<int> ans;
            int cntx = 0, cnty = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == vx) cntx++;
                else if(nums[i] == vy) cnty++;
            }
            if(cx != 0 && cntx > nums.size() / 3) ans.push_back(vx);
            if(cy != 0 && cnty > nums.size() / 3) ans.push_back(vy);
        return ans;
    }
};
