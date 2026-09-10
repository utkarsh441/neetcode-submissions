class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int done = -1e9;
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            if(done == nums[i]) continue;
            int j= i + 1, k = n - 1;
            int tar = -(nums[i]);
            set<vector<int>>st;
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum == tar && st.count({nums[j], nums[k]}) == 0) {
                    st.insert({nums[j], nums[k]});
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // break;
                }
                if(sum > tar) k--;
                else j++;
            }
            done = nums[i];
        }
        return ans;
    }
};
