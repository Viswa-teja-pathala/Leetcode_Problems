#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int x = original.size();
        vector<vector<int>> matrix(m, vector<int>(n));  // Initialize the 2D matrix

        if (x != m * n) {
            return {};  // Return an empty vector if dimensions don't match
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = original[count];
                count++;
            }
        }

        return matrix;
    }
};
