class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n =chalk.size();
        long long int sum = 0;
        for(int i=0; i<n; i++){
            sum += chalk[i];
        }

        while(sum <= k){
            k = k - sum;;
        }

        for(int i=0; i<n; i++){
           if(k < chalk[i]){
            return i;
           } else{
            k -= chalk[i];
           }
        }

        return 0;
    }
};