class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int min_time = high;

        while(low <= high){
            int k = (low + high) / 2;
            int hours = 0;
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + k - 1) / k; //ceil(piles[i]/k)
            }
        
            if(hours <= h){
                // k is valid, can try smaller
                min_time = k;
                high = k - 1;
            } else {
                // k is not valid, we need a bigger number
                low = k + 1;
            }
        }
        
        
    }
};
