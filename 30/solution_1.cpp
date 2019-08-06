class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size()==0) return {};
        int word_length = words[0].length();
        if (s.length() < words.size() * word_length) return {};
        unordered_map<string, int> dict_origin;
        for(auto word: words){
            if (dict_origin.find(word)!=dict_origin.end()){
                ++dict_origin[word];
            } else {
                dict_origin.insert({word, 1});
            }
        }
        
        for(int i=0;i<=s.length() - words.size() * word_length;++i){
            string tmp = s.substr(i, word_length);
            if (dict_origin.count(tmp)){
                unordered_map<string, int> dict_tmp = dict_origin;
                --dict_tmp[tmp];
                bool matchFlag = true;
                for (int j=1;j<words.size();++j){
                    string tmp = s.substr(i + j * word_length, word_length);
                    if (dict_tmp.find(tmp) == dict_tmp.end() || dict_tmp[tmp] < 1){
                        matchFlag = false;
                        break;
                    } else {
                        --dict_tmp[tmp];
                    }
                }
                if (matchFlag) {
                    result.push_back(i);
                }
            }
        }
        
        return result;
    }
};