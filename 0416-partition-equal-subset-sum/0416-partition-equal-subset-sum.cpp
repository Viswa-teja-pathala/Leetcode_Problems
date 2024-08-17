class Solution {
public:
    bool func(int ind, vector<int> &arr, int target, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (ind < 0) return false;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = func(ind - 1, arr, target, dp);
        bool take = false;
        if (arr[ind] <= target) {
            take = func(ind - 1, arr, target - arr[ind], dp);
        }

        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

        return func(n - 1, nums, sum / 2, dp);
    }
};
