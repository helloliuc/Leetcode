class Solution {
public:
    int myAtoi(string str) {
        int p;
        while(p < str.length() && str[p] == ' ') p++;
        
        int flag = 1;
        if(p < str.length()) {
            if(str[p] == '+') {
                p++;
            }
            else if(str[p] == '-') {
                flag = -1;
                p++;
            }
            else if(str[p] < '0' || str[p] > '9') {
                return 0;
            }
        }
        int ret = 0;
        while(p < str.length()) {
            if(!(str[p] >= '0' && str[p] <= '9')) {
                return ret;
            }
            if(flag == 1) {
                if(INT_MAX / 10 < ret) {
                    return INT_MAX;
                }
                if(INT_MAX - (str[p] - '0') < ret * 10) {
                    return INT_MAX;
                }
                else {
                    ret = ret * 10 + flag * (str[p] - '0');
                }
            }
            else {
                if(INT_MIN / 10 > ret) {
                    return INT_MIN;
                }
                if(INT_MIN + (str[p] - '0') > ret * 10) {
                    return INT_MIN;
                }
                else {
                    ret = ret * 10 + flag * (str[p] - '0');
                }
            }
            p++;
        }
        return ret;
    }
};
