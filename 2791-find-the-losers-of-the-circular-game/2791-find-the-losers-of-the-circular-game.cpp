class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vec(n, 0);  
        int i = 0;  
        int j = 1; 
        while (vec[i] != 2) {
            vec[i]++;  
            if (vec[i] == 2) break;  
            
            i = (i + j * k) % n;
            j++;  
        }
        
        vector<int> ans;
        for (int x = 0; x < n; x++) {
            if (vec[x] == 0) {  
                ans.push_back(x + 1);  
            }
        }

        return ans;
    }
};
