class Solution {
public:
    void result(int i, vector<int>& dp, int sum, const vector<int>& candidates, int target, vector<vector<int>>& dp1) {
        if (sum == target) {
            dp1.push_back(dp);  // Add current combination to dp1
            return;
        }

        if (i == candidates.size() || sum > target) {
            return;  // Base case: stop recursion if i exceeds array size or sum exceeds target
        }

        // Include candidates[i] in the current combination
        dp.push_back(candidates[i]);
        result(i, dp, sum + candidates[i], candidates, target, dp1);
        
        // Exclude candidates[i] from the current combination
        dp.pop_back();
        result(i + 1, dp, sum, candidates, target, dp1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> dp1;
        vector<int> dp;
        result(0, dp, 0, candidates, target, dp1);
        return dp1;
    }
};
