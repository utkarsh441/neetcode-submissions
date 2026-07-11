#include <cstring>
class Solution {
public:
    int dp[101][5001];
    bool helper(int idx, int target, vector<int>&nums) {
        if(idx == nums.size()) {
            if(target == 0) return true;
            return false;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        bool take = false;
        if(nums[idx] <= target) take = helper(idx + 1, target - nums[idx], nums);
        bool nottake = helper(idx + 1, target, nums);
        return dp[idx][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        memset(dp, -1, sizeof(dp));
        return helper(0, sum/2, nums);
    }
};
