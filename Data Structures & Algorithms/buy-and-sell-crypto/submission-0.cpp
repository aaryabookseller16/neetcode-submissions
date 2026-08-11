class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r =1;
        int maxP = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r]){ // valid window
                int profit = prices[r] - prices[l];
                maxP = max(profit,maxP);
            } else{ //invalid window
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
