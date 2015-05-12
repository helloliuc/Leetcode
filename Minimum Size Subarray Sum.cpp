//1A
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(int lt=0, rt=0; rt < n; rt++) {
            sum += nums[rt];
            while(sum - nums[lt] >= s) {
                sum -= nums[lt];
                lt++;
            }
            if(sum >= s) {
                if(ans == 0 || rt-lt+1 < ans) {
                    ans = rt - lt + 1;
                }
            }
        }
        return ans;
    }
};
