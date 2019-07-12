class Solution {
public:
    string intToRoman(int num) {
        int Symbol_size[] = {1000, 500, 100, 50, 10, 5, 1};
        string output = "";
        int i = num / 1000;
        for(;i>0;--i) output += "M";
        
        num = num % 1000;
        i = num / 100;
        if (i==9){
            output+="CM";
        } else if (i>=5){
            output+="D";
            i-=5;
            for(;i>0;--i){
                output+="C";
            }
        } else if (i==4){
            output+="CD";
            
        } else if (i>0) {
            for(;i>0;--i){
                output+="C";
            }
        }
        
        num = num % 100;
        i = num / 10;
        if (i==9){
            output+="XC";
        } else if (i>=5){
            output+="L";
            i-=5;
            for(;i>0;--i){
                output+="X";
            }
        } else if (i==4){
            output+="XL";
        } else if (i>0) {
            for(;i>0;--i){
                output+="X";
            }
        }
        
        num = num % 10;
        if (num==9){
            output+="IX";
        } else if (num>=5){
            output+="V";
            num-=5;
            for(;num>0;--num){
                output+="I";
            }
        } else if (num==4){
            output += "IV";
        } else {
            for(;num>0;--num){
                output+="I";
            }
        }
        return output;
    }
};