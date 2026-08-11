class Solution {
public:
    int findMin(vector<int> &nums) {
       int res = nums[0];
       int l = 0;
       int r = nums.size() - 1;

       while(l <= r){
        // termination condition
        if(nums[l] < nums[r]){
            res = min(res, nums[l]);
            break;
        }

        int m = l + (r-l)/2;
        res = min(res,nums[m]);

        if(nums[m] >= nums[l]){ //if middle is greater than left, search right
            l = m+1;
        } else { // if middle is less than left, search left
            r = m-1;
        }
    }
    return res;
    }
};
