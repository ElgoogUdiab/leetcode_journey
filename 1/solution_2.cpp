class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int max_element = INT_MIN, min_element = INT_MAX;
        vector<int> result{0,0};
        unordered_map<int, int> table;
        
        for(auto it=nums.begin();it!=nums.end();++it){
            if (table.find(*it)==table.end()){
                table[target-*it]=it-nums.begin();
            } else {
                result[1]=it-nums.begin();
                result[0]=table[*it];
                break;
            }
        }
        return result;
    }
};