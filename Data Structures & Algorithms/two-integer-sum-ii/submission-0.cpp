class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int i = 0 , j = numbers.size() - 1;

        for(int i = 0; i < numbers.size(); i++){
            for(int j = 0; j < numbers.size(); j++){
                int difference = target - numbers[i];
                if(i != j && numbers[j] == difference){
                    return {i+1,j+1};
                }
            }
        }
        return {};
    }
};
