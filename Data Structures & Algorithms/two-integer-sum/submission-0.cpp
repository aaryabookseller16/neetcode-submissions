class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices; //val-> index

        //map the corresponding elements with their array indices
        for(int i = 0; i < nums.size(); i++){
            indices[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if(indices.count(difference) && indices[difference] != i){
                return {i, indices[difference]};
            }
        }

        return {};
    }
};
