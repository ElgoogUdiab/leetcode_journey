class Solution {
public:
    int value(char c){
        switch (c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int result=0, last_val = 0;
        for (int i=s.length()-1;i>=0;--i){
            int curr_val = value(s[i]);
            if (curr_val >= last_val){
                result+=curr_val;
                last_val = curr_val;
            } else {
                result-=curr_val;
            }
        }
        return result;
    }
};