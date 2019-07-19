class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i=0; i<s.length();++i){
            switch (s[i]){
                case '(':
                    stack.push_back('(');
                    break;
                case '[':
                    stack.push_back('[');
                    break;
                case '{':
                    stack.push_back('{');
                    break;
                default:{
                    if (stack.size()==0) return false;
                    char x = stack.back();
                    stack.pop_back();
                    if (!(x=='(' && s[i]==')' || x == '[' && s[i]==']' || x=='{' && s[i]=='}')){
                        return false;
                    }
                }
                    
            }       
        }
        return stack.size()==0;
    }
};