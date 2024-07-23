class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int x = mid / m;
            int y = mid % m;

            if (mat[x][y] == target) {
                return true;
            } else if (mat[x][y] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
