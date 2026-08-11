class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int> area;

        for(int i = 0; i < heights.size(); i++){
            for (int j = i + 1; j < heights.size(); j++) { // fix: j starts from i+1
                if (heights[i] <= heights[j]) {
                    area.push_back(heights[i] * (j - i));
                } else {
                    area.push_back(heights[j] * (j - i));
                }
            }
        }
        auto max_it = max_element(area.begin(), area.end());
        int max_value = *max_it;

        return max_value;
    }
};
