class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return 1;
        }
        sort(nums.begin(), nums.end());
        int count = 1;
        int num = nums[0];
        int maxi = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(num+1 == nums[i])
            {
                num = nums[i];
                count++;
            }
            else if(num == nums[i])
            {
                continue;
            }
            else
            {
                num = nums[i];
                count = 1;
            }
            maxi = max(count, maxi);
        }

        return maxi;
    }
};