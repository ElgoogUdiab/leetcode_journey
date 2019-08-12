class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int word_length, n;
        // The pre-solve check.
        // word_length and n are initialized only when they are needed.
        if(s.empty() || words.empty() || s.length() < (n = words.size()) * (word_length = words[0].length())) return {};

        // Initializing the dict.
        unordered_map<string, int> dict_origin;
        for(auto word: words) ++dict_origin[word];

        // Declear the hash table outside the loop since destruct then reconstruct is much slower than a clear().
        int count = 0; unordered_map<string, int> dict_tmp;

        for(int j=0; j<word_length; ++j) {
            // word_length * n + j > s.length() is necessary to be true to construct a solution
            // j is increasing
            // so when the j gets big enough we can stop the loop immediately
            if (j + word_length * n > s.length()) break;

            // The main loop
            // The ending condition indicates that starting from position i, there must be enough length to construct a solution based on the current situation.
            // For example, when there are only two words left in the string, with no previous words, and three words are required, there will be no solution.
            for(int i=0; (i + n - count) * word_length + j <= s.length(); ++i){
                int start_point = i * word_length + j;
                string tmp = s.substr(start_point, word_length);
                if (dict_origin.find(tmp) != dict_origin.end()){
                    ++dict_tmp[tmp];
                    // If one word has more than what is required, move the starting point.
                    while (dict_tmp[tmp] > dict_origin[tmp]){
                        // decrement the count in dict_tmp(to update the dict) and count (to move the starting point).
                        --dict_tmp[s.substr(start_point - (count--) * word_length, word_length)];
                    }
                    // Since there is a match, count is incremented.
                    ++count;

                    // When a solution is found, take it as a result, then move the start point by one word.
                    if (count == n){
                        int result_pos = start_point - (--count) * word_length;
                        result.push_back(result_pos);
                        --dict_tmp[s.substr(result_pos, word_length)];
                    }
                } else {
                    dict_tmp.clear(); count = 0;
                }
            }
            dict_tmp.clear(); count = 0;
        }
        
        return result;
    }
};