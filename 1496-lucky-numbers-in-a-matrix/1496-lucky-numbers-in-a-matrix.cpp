class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> vec;
        int k;
        for(int i=0; i<m; i++)
        {
            int x=0;
            int count1 = matrix[i][0];
            k =0;
            for(int j=1; j<n; j++)
            {
                if(count1 > matrix[i][j])
                {
                    count1 = matrix[i][j];
                    k = j;
                }
            }
            bool flag = true;
            for(int row = 0; row<m; row++)
            {
                if (matrix[row][k] > count1) {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                vec.push_back(count1);
            }
        }
        return vec;
    }
};