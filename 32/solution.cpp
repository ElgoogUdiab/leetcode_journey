class Solution {
public:
    int longestValidParentheses(string s) {
        int s_length = s.length(), max_result = 0;
        if (s_length < 2) return 0;
        if (s_length == 2) return s == "()" ? 2 : 0;
        int dp[s_length] {0};
        
        if (s[0] == '(' && s[1] == ')') {
            dp[1] = 2;
            max_result = 2;
        }
        for (int i = 2; i < s_length; ++i){
            if (s[i] == ')'){
                if (s[i-1] == '('){
                    dp[i] = dp[i-2] + 2;
                } else {
                    if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '('){
                        dp[i] = dp[i-1] + 2;
                        if (i - dp[i-1] - 2 >= 0) dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
            if (dp[i] > max_result) max_result = dp[i];
        }
        return max_result;
    }
};