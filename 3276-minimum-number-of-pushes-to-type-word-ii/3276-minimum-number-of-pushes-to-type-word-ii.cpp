class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        int ans = 0;
        map<char, int> mp;
        
        // Count frequency of each character
        for(char c : word) {
            mp[c]++;
        }
        
        // Convert map to vector of pairs
        vector<pair<char, int>> freqVector(mp.begin(), mp.end());
        
        // Sort vector based on frequency in descending order
        sort(freqVector.begin(), freqVector.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        
        // Calculate the cost based on the sorted frequencies
        for(int i = 0; i < freqVector.size(); i++) {
            int freq = freqVector[i].second;
            count++;
            if(count <= 8) {
                ans += freq * 1;
            } else if(count <= 16) {
                ans += freq * 2;
            } else if(count <= 24) {
                ans += freq * 3;
            } else {
                ans += freq * 4;
            }
        }

        return ans;
    }
};