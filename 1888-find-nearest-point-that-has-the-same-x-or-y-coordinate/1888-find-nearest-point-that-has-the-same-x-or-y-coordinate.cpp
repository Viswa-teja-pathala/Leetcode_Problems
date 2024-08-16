class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int mini = INT_MAX;
        int ind = -1;
        for(int i=0; i<n; i++){
            if(points[i][0] == x || points[i][1] == y){
                int dist = abs(x-points[i][0]) + abs(y-points[i][1]);
                if(mini > dist){
                mini = min(mini, dist);
                ind = i;
                }
            }

        }

        return ind;
    }
};