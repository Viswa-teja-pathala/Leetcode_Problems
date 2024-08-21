class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(i=0; i<n; i++){
            if(nums[i] == 1){
                break;
            }
        }
        int j=0;
        for(j=n-1; j>=0; j--){
            if(nums[j] == n){
                break;
            }
        }

        if(j<i){
            return (i + n-j-2);
        }

        return (i + n-j-1);
    }
};