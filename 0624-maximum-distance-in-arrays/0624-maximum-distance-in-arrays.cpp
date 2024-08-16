class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0].back();
        int maxDist = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();
            
            maxDist = max(maxDist, abs(currentMax - globalMin));
            maxDist = max(maxDist, abs(globalMax - currentMin));
            
            globalMin = min(globalMin, currentMin);
            globalMax = max(globalMax, currentMax);
        }

        return maxDist;
    }
};
