class Solution {
public:
    int numberOfChild(int n, int k) {
        int x = k/(n-1);
        int y = k%(n-1);

        if(x%2 == 0){
            return 0+y;
        }else{
            return n-1-y;
        }

        return 0;
    }
};