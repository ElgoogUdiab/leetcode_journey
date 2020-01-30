class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string temp; char curr_char; int count;
        while (--n){
            temp = ""; curr_char = result[0]; count = 1;
            for (int pos = 1; pos < result.length(); pos++){
                if (curr_char == result[pos]) {
                    count++;
                } else {
                    temp.append(to_string(count) + curr_char);
                    curr_char = result[pos]; count = 1;
                }
            }
            result = temp + to_string(count) + curr_char;
        }
        return result;
    }
};