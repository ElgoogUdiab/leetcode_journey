class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrace(result, "(", 1,0,n);
        return result;
    }
    void backtrace(vector<string>& result, string current, int left, int right, int n){
        if (left == n){
            for (int i = right;i<n;++i) current+=")";
            result.push_back(current);
            return;
        } else if (right > left) {
            return;
        } else {
            backtrace(result, current+"(", left+1, right, n);
            backtrace(result, current+")", left, right+1, n);
            return;
        }
    }
};