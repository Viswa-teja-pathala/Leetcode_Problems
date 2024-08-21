class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            int pos = s[i] - 'a' + 1;
            if(pos < 10){
                sum  += pos;
            }else{
                sum = sum + pos/10;
                sum = sum + pos%10;
            }
        }

        for(int i=1; i<k; i++){
            int res = 0;
            if(sum < 10){
                return sum;
            }

            while(sum!=0){
                res = res + sum%10;
                sum = sum/10;
            }
            sum = res;
        }
        return sum;
    }
};