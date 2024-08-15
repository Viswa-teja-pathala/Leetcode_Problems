class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count = 0;
        int count1 = 0;

        for(int i=0; i<bills.size(); i++){
            if(count < 0){
                return false;
            }
            if(bills[i] == 5){
                count++;
            }else if(bills[i] == 10){
                count--;
                count1++;
            }else{
                if(count1 > 0){
                    count1--;
                    if(count > 0){
                        count--;
                    }else{
                        return false;
                    }
                }else if(count >=3){
                    count = count - 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};