class Solution {
public:
    int maxArea(vector<int>& height) {
        int global_max=0, i=0, j=height.size()-1;
        while(i!=j){
            if (min(height[i],height[j])*(j-i)>global_max){
                global_max = min(height[i],height[j])*(j-i);
            }
            if (height[i]>height[j]){
                --j;
            } else {
                ++i;
            }
        }
        return global_max;
    }
};