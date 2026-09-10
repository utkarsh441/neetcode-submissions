class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0, j = n - 1;
        while(i <= j) {
            ans ++;
            int r = limit - nums[j];
            j--;
            if(i > j) break;
            if(r >= nums[i]) i++; 
        }
        return ans;
    }
};