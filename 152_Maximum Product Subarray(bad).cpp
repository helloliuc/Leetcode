class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        int positive_max = INT_MIN, negative_max = INT_MIN;
        int ans = INT_MIN;
        bool flag = false;
        for(auto num : nums) {
            if(num > 0) {
                if(positive_max == INT_MIN) positive_max = num;
                else positive_max *= num;
                if(negative_max != INT_MIN) negative_max *= num;
            }
            else if(num < 0) {
                int tmp = positive_max;
                if(negative_max != INT_MIN) {
                    positive_max = negative_max * num;
                }
                else {
                    positive_max = INT_MIN;
                }
                
                if(tmp != INT_MIN) {
                    negative_max = tmp * num;
                }
                else {
                    negative_max = num;
                }
            }
            else {
                positive_max = INT_MIN;   negative_max = INT_MIN;
                if(ans < 0) ans = 0;
            }
            if(positive_max > ans) ans = positive_max;
            if(negative_max > ans) ans = negative_max;
        }
        return ans;
    }
};
