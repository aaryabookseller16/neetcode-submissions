class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int area = 0;

        while(l < r){
            if(height[r] > height[l]){
                if(height[l] > leftMax){
                    leftMax = height[l];
                } else{
                    area += leftMax - height[l];
                }
                l++;
            } else{
                if(height[r] > rightMax){
                    rightMax = height[r];
                } else{
                    area += rightMax - height[r];
                }
                r--;
            }
        }
        return area;
    }
};
