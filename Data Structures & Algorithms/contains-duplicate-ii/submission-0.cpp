class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i = 0; i <= min(n - 1, k); i++) {
            if(st.count(nums[i]) == 0)st.insert(nums[i]);
            else return true;
        }
        for(int i = k + 1; i < nums.size(); i++) {
            st.erase(nums[i - k - 1]);
            if(st.count(nums[i])) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};