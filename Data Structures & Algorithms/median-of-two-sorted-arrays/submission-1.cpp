class Solution {
public:
    vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int p1 = 0, n1 = nums1.size();
        int p2 = 0 ,n2 = nums2.size();
        vector<int> result;

    
        while(p2 < n2 && p1 < n1){
            if(nums1[p1] < nums2[p2]){
                result.push_back(nums1[p1]);
                p1++;
            } else if(nums1[p1] > nums2[p2]){
                result.push_back(nums2[p2]);
                p2++;
            } else{
                result.push_back(nums1[p1]);
                result.push_back(nums2[p2]);
                p1++;
                p2++;
            }
        }
       
       while(p1 < n1) result.push_back(nums1[p1++]);
       while(p2 < n2) result.push_back(nums2[p2++]);
       
       
       return result;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedVector = mergeSortedArrays(nums1, nums2);

        int sizeMerged = mergedVector.size();
        int mid = -1;
        double median = -1.0;
        if(sizeMerged % 2 == 1){ //vector of odd length
            mid = sizeMerged/2.0;
            median = mergedVector[mid];
            return median;
        } else{ // vector of even length
            mid = (sizeMerged/2)-1;
            median = (mergedVector[mid] + mergedVector[mid+1])/2.0;
            return median;

    }
    return -1;
    }
};
