class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ans = "";
        int carry = 0;
        while(i >= 0 && j >= 0) {
            if(a[i] == b[j]) {
                if(a[i] == '0') {
                    ans += '0' + carry;
                    carry = 0;
                } 
                else {
                    if(carry == 0) ans += '0';
                    else ans += '1';
                    carry = 1;
                }
            }

            else {
                if(carry == 0) ans += '1';
                else ans += '0';
            }
            i--;
            j--;
        }

        while(i >= 0) {
            if(a[i] == '1') {
                if(carry == 0) ans += '1';
                else ans += '0';
            }
            else {
                if(carry == 0) ans += '0';
                else {
                    ans += '1';
                    carry = 0;
                }
            }
            i--;
        }

        while(j >= 0) {
            if(b[j] == '1') {
                if(carry == 0) ans += '1';
                else ans += '0';
            }
            else {
                if(carry == 0) ans += '0';
                else {
                    ans += '1';
                    carry = 0;
                }
            }
            j--;
        }
        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};