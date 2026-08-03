class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // Set max profit to 0 and initial buy price to the first day's price
        int maxProfit = 0, buyPrice = prices[0];

        // Loop through the rest of the days starting from day 1
        for (int i = 1; i < prices.size(); i++) {
            // If current price is greater than buy price, check if profit is higher
            if (prices[i] > buyPrice) {
                maxProfit = max(maxProfit, (prices[i] - buyPrice));
            }
            // Otherwise, update buy price to the lower current price
            else {
                buyPrice = min(buyPrice, prices[i]);
            }
        }

        // Return the final maximum profit found
        return maxProfit;
    }
};
