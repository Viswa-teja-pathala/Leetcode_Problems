class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int m = numRows;
        vector<vector<int>> v;
        for(int i =1;i<=m;i++){
            vector<int> a(i,1);
            v.push_back(a);
        }
        
        for(int i = 0;i<m;i++){
            for(int j=1;j<i;j++){
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};