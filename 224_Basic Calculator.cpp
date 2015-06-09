class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int p = 0;
        int num = 0;
        char op = '+';
        while(p < s.length()) {
            while(p < s.length() && s[p] == ' ') p++;
            if(p == s.length()) break;
            if(s[p] == '(') {
                nums.push(num);
                ops.push(op);
                num = 0; op = '+';
                p++;
            }
            else if(s[p] == ')') {
                if(ops.top() == '+') {
                    num = nums.top() + num;
                }
                else {
                    num = nums.top() - num;
                }
                nums.pop(); ops.pop();  p++;
            }
            else if(s[p] == '+' || s[p] == '-') {
                op = s[p++];
            }
            else {
                int newnum = 0;
                while(p < s.length() && s[p] >= '0' && s[p] <= '9') {
                    newnum = newnum * 10 + s[p] - '0';
                    p++;
                }
                if(op == '+') {
                    num += newnum;
                }
                else {
                    num -= newnum;
                }
            }
        }
        return num;
    }
};
