class Solution {
public:
    struct args{
        string current_str;
        int left;
        int right;
        args(string c, int l, int r): current_str(c), left(l), right(r) {}
    };
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<args> stack;
        stack.push_back({"(", 1, 0});
        while (stack.size()){
            args arg = stack.back();
            stack.pop_back();
            if (arg.left==n){
                for (int i = arg.right;i<n;++i) arg.current_str+=")";
                result.push_back(arg.current_str);
                continue;
            } else if (arg.right > arg.left){
                continue;
            } else {
                stack.push_back({arg.current_str+")", arg.left, arg.right+1});
                stack.push_back({arg.current_str+"(", arg.left+1, arg.right});
                continue;
            }
        }
        return result;
    }
};