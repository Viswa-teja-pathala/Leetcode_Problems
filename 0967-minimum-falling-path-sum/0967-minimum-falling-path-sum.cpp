class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Create a DP table to store the minimum path sums
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Initialize the last row of the DP table with the values from the matrix
        for (int j = 0; j < m; ++j) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        
        // Fill the DP table from the bottom up
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                // Calculate minimum path sum for cell (i, j)
                int down = dp[i + 1][j];
                int down_left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int down_right = (j < m - 1) ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(down, min(down_left, down_right));
            }
        }
        
        // Find the minimum value in the top row of the DP table
        int result = INT_MAX;
        for (int j = 0; j < m; ++j) {
            result = min(result, dp[0][j]);
        }
        
        return result;
    }
};
