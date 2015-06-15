class Solution {
public:
    string addBinary(string a, string b) {
        int i, j;
        string ans = "";
        int carry = 0;
        for(i=a.size()-1, j=b.size()-1; i>=0 && j>=0; i--, j--) {
            int tmp = a[i] - '0' + b[j] - '0' + carry;
            ans.insert(ans.begin(), tmp%2 + '0');
            carry = tmp / 2;
        }
        while(i >= 0) {
            int tmp = a[i] - '0' + carry;
            ans.insert(ans.begin(), tmp%2 + '0');
            carry = tmp / 2;
            i--;
        }
        while(j >= 0) {
            int tmp = b[j] - '0' + carry;
            ans.insert(ans.begin(), tmp%2 + '0');
            carry = tmp / 2;
            j--;
        }
        if(carry == 1) {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
};
