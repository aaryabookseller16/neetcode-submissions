class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        vector<int> ans;
        while(right < nums.size()){
            int max = *max_element(nums.begin() + left, nums.begin() + right+1);
            ans.push_back(max);
            left++;
            right++;
        }
        return ans;
    }
};
