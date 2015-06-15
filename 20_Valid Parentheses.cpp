class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(int i=0; i<str.length(); i++) {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') s.push(str[i]);
            else switch(str[i]) {
                case '}' : {
                    if(s.empty() || s.top() != '{') return false;
                    s.pop();    break;
                }
                case ')' : {
                    if(s.empty() || s.top() != '(') return false;
                    s.pop();    break;
                }
                case ']' : {
                    if(s.empty() || s.top() != '[') return false;
                    s.pop();    break;
                }
                default : return false;
            }
        }
        return s.empty();
    }
};
