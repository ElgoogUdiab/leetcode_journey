class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Use two vectors, avoiding copying the whole vector.
        // When dealing with digits[odd], seed is result[0], store in result[1]
        // However when digits[even], seed is result[1], store in result[0]

        // Empty string input, empty vector output
        if (digits=="") return {};
        
        // '2'(50) -> 0, therefore use (char - 50) to get the index.
        vector<vector<char>> num2char {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> result[2];
        // Pushing the seed.
        result[1].push_back("");
        for(int i=0;i<digits.length();++i){
            // Clear the place
            result[i & 1].clear();
            for(auto seed: result[!(i & 1)]){
                for(auto add_char: num2char[digits[i]-50]){
                    result[i & 1].push_back(seed+add_char);
                }
            }
        }
        return result[!(digits.length() & 1)];
    }
};