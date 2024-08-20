class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int x = n-1;
        int sum = 0;

        while(x-2 >= 0 ){
            sum += cost[x];
            sum += cost[x-1];
            x = x-3;
        }
        if(x >= 0){
            sum += cost[x];
        }
        if(x-1 >=0){
            sum+=cost[x-1];
        }

        return sum;
    }
};