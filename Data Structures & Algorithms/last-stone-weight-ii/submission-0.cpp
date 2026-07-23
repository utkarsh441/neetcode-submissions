#include<bits/stdc++.h>
class Solution {
public:
    int dp[31][3001];
    int helper(int idx, int sum, vector<int>&nums) {
        if(idx >= nums.size()) {
            if(sum < 0) return 1e9;
            return sum;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int add = helper(idx + 1, sum + nums[idx], nums);
        int sub = helper(idx + 1, sum - nums[idx], nums);
        return dp[idx][sum] = min(add, sub);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        int ans = helper(0, 0, stones);
        return ans;
    }
};