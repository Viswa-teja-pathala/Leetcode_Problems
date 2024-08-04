class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<long long> ans;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        // Generate all subarray sums and add to minHeap
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                minHeap.push(sum);
            }
        }

        // Get the sum of elements in the range [left, right]
        long long res = 0;
        for (int i = 1; i <= right; ++i) {
            long long currentSum = minHeap.top();
            minHeap.pop();
            if (i >= left) {
                res = (res + currentSum) % MOD;
            }
        }
        
        return res;
    }
};