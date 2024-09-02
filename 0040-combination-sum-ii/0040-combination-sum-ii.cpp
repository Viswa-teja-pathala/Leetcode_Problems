class Solution {
public:
    void result(int start, vector<int>& dp, int sum, const vector<int>& candidates, int target, vector<vector<int>>& dp2) {
        if (sum == target) {
            dp2.push_back(dp);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;  
            }
            dp.push_back(candidates[i]);
            result(i + 1, dp, sum + candidates[i], candidates, target, dp2);
            dp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        vector<vector<int>> dp2;
        vector<int> dp;
        result(0, dp, 0, candidates, target, dp2);
        return dp2;
    }
};
