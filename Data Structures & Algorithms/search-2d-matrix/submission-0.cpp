class Solution {
public:
    //1d binary search for the rows
    int binarySearch(vector<int>& nums, int target, int low, int high){
        if (low > high) return -1;
        int mid = (low + high) / 2;
        if (target < nums[mid]) {
            return binarySearch(nums, target, low, mid - 1);
        } else if (target > nums[mid]) {
            return binarySearch(nums, target, mid + 1, high);
        } else {
            return mid;
        }
    }

    bool twoDBinarySearch(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            int colSize = matrix[i].size();
            if (binarySearch(matrix[i], target, 0, colSize - 1) != -1) {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return twoDBinarySearch(matrix, target);
    }
};
