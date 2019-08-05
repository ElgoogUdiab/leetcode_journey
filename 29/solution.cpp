class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        unsigned int dividend_u, divisor_u;
        dividend_u = dividend > 0 ? dividend : (dividend == INT_MIN ? 2147483648u : -dividend);
        divisor_u = divisor > 0 ? divisor : (divisor == INT_MIN ? 2147483648u : -divisor);
        
        bool sign = ((dividend ^ divisor) >> 31) & 0x00000001;
        
        int result_len = int_len(dividend_u)-int_len(divisor_u);
        int result = 0;
        
        for(int i = result_len; i>=0; --i){
            // cout << dividend_u << " " << (divisor_u << i) << " " << result << endl;
            if (dividend_u > (divisor_u << i)){
                // cout << "Hello" << endl;
                set_1(result, i);
                dividend_u -= (divisor_u << i);
            } else if (dividend_u == (divisor_u << i)){
                set_1(result, i);
                return sign ? -result : result;
            }
        }
        
        return sign ? -result : result;
    }
    
    char int_len(unsigned int the_int){
        if (the_int == 2147483648u) return 31;
        // cout << the_int << " ";
        char result=16;
        int k = 8;
        while (k){
            // cout << (int)result << " ";
            if ((the_int >> result) == 1){
                return result;
            } else {
                if ((the_int >> result) == 0) {
                    result -= k;
                } else {
                    result += k;
                }
                k >>=1;
            }
        }
        // cout << (int)result << endl;
        return result;
    }
    
    void set_1(int& val, int pos){
        val = val | (1 << pos);
    }
};