class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, pre_dis = 0, cur_dis = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > pre_dis) {
                steps ++;
                pre_dis = cur_dis;
                if(i > cur_dis) return -1;
            }
            cur_dis = max(cur_dis, i + nums[i]);
        }
        return steps;
    }
};
