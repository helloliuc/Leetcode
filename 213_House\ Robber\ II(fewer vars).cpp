class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int f=nums[0], f1=0;
        int g=0, g1=0;
        for(int i=1; i<nums.size()-1; i++) {
            swap(f, f1);    swap(g, g1);
            f = max(f1, f+nums[i]);
            g = max(g1, g+nums[i]);
        }
        g = max(g, g1+*(nums.end()-1));
        return max(f, g);
    }
};
