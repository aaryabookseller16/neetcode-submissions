class Solution {
public:
    int binarySearch(vector<int> nums, int target, int low, int high){
        if(low > high){
            return -1;
        }
        int mid = (low + high)/2;
        
        if(target > nums[mid]){
            return binarySearch(nums, target, mid+1, high);
        } else if(target < nums[mid]){
            return binarySearch(nums, target, low, mid-1);
        } else{
           return mid;
        }
    }    
    
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int ans = binarySearch(nums, target,low, high);
        return ans;
        }
};
