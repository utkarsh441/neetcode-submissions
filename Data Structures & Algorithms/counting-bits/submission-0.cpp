class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i = 0; i <= n; i++) {
            int ans = 0;
            for(int j = 0; j < 32; j++) {
                ans += ((i >> j) & 1);
            }
            v.push_back(ans);
        }
        return v;
    }
};
