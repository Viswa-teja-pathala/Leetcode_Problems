class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+1, -1);

        for(int i=0; i<n; i++){
            vec[nums[i]] = 1;
        }
        vector<int> ans;
        for(int i=1; i<=n;  i++){
            if(vec[i] == -1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};