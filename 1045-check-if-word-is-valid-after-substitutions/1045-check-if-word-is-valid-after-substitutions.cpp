class Solution {
public:
    bool isValid(string s) {
        string t = s;
        int i=0;
        int n = s.size();
        int j=0;
        while((i+3)<=t.size()){
            string str = t.substr(i, 3);

            if(str == "abc"){
                t.erase(i, 3); 
                i=0;
            }else{
                i++;
            }
        }

        if(t == ""){
            return true;
        }
        return false;;

    }
};