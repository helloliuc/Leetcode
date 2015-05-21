class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int f=nums[0],f1=nums[0],f2=0;
        int g=0,g1=0,g2=0;
        for(int i=1;i<nums.size()-1; i++) {
            f = max(f1, f2+nums[i]);
            g = max(g1, g2+nums[i]);
            f2 = f1;    f1 = f;
            g2 = g1;    g1 = g;
        }
        g = max(g1, g2+nums[nums.size()-1]);
        return max(f, g);
    }
};
