class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> mp1;
        map<char, int> mp2;
        int count1 = 0, count2 = 0;
        for(int i=0; i<5; i++){
            mp1[ranks[i]]++;
            count1 = max(count1, mp1[ranks[i]]);
        }

        for(int i=0; i<5; i++){
            mp2[suits[i]]++;
            count2 = max(count2, mp2[suits[i]]);
        }

        if(count2 == 5){
            return "Flush";
        }else if(count1 >=3){
            return "Three of a Kind";
        }else if(count1>=2){
            return "Pair";
        }else{
            return "High Card";
        }
        return "";
    }
};