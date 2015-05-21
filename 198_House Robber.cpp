class Solution {
public:
    int rob(vector<int>& nums) {
        int current=0, last1=0, last2=0;
        for(int i=0; i<nums.size(); i++) {
            current=max(last1, last2+nums[i]);
            last2 = last1;
            last1 = current;
        }
        return current;
    }
};
