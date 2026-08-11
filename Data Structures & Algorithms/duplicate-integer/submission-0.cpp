class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> ans(nums.begin(), nums.end());
        int setSize = ans.size();
        int vectorSize = nums.size();

        if(setSize == vectorSize){
            return false;
        } else if(setSize < vectorSize){
            return true;
        } 
        return false;
    }
};
