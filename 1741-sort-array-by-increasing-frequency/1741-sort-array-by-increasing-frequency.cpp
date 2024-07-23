class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }   
        auto cmp = [&](int a, int b) {
            if (mp[a] != mp[b]) {
                return mp[a] < mp[b];
            } else {
                return a > b; 
            }
        };
        sort(nums.begin(), nums.end(), cmp);
        
        return nums;
    }
};