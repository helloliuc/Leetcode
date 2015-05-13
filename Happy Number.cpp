class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)  return false;
        set<int> vis;
        while(n!=1) {
            int sum = 0;
            while(n!=0) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if(vis.find(sum) != vis.end()) {
                return false;
            }
            vis.insert(sum);
            n = sum;
        }
        return true;
    }
};
