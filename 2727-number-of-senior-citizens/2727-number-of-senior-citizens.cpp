class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(int i=0; i<details.size(); i++){
            int sum = details[i].at(11) - '0';
            sum = sum*10 + (details[i].at(12) - '0');
            if(sum > 60){
                count++;
            }
        }

        return count;
    }
};