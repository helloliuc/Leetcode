class Solution {
public:
    bool isValidChar(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    char tolower(char c) {
        if(c >= 'A' && c <= 'Z') {
            c = c + 'a' - 'A';
        }
        return c;
    }
    bool isPalindrome(string s) {
        int lt = 0, rt = s.length() -1;
        while(lt < rt) {
            while(lt < s.length() && !isValidChar(s[lt])) lt++;
            while(rt >= 0 && !isValidChar(s[rt])) rt--;
            if(lt <= rt) {
                if(tolower(s[lt]) != tolower(s[rt])) {
                    return false;
                }
                lt++; rt--;
            }
        }
        return true;
    }
};
