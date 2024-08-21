class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        double  sum = 0;
        int n= salary.size();
        if(n<3){
            return 0;
        }
        for(int i=0; i<n; i++){
            sum += salary[i];
            mini = min(mini, salary[i]);
            maxi = max(maxi, salary[i]);
        }

        sum = sum - mini;
        sum = sum - maxi;

        sum = (double)(sum/(n-2));

        return sum;
    }
};