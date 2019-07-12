class Solution {
public:
    int maxArea(vector<int>& height) {
        int global_max=0;
        for (int i=0;i<height.size()/2;++i){
            int possible_max = ((height.size()-1)-i)*height[i];
            if (possible_max < global_max) continue;
            for (int j=height.size()-1;j>i;--j){
                if ((j-i)*min(height[i],height[j]) > global_max){
                    global_max = (j-i)*min(height[i],height[j]);
                }
            }
        }
        for (int i=height.size()-1; i>=height.size()/2; --i){
            int possible_max = (i-1)*height[i];
            if (possible_max < global_max) continue;
            for (int j=0;j<i;++j){
                if ((i-j)*min(height[i],height[j]) > global_max){
                    global_max = (i-j)*min(height[i],height[j]);
                }
            }
        }
        return global_max;
    }
};