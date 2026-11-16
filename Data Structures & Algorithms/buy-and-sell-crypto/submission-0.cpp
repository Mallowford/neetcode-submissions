class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Brute Force (Intuition)
        vector<int> profit(prices.size(), 0);

        for (int i = 0; i < prices.size() - 1; i++) {
            int buyPrice = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                int sellPrice = prices[j];
                profit[i] = max(profit[i], sellPrice - buyPrice);
            };
        };

        return *max_element(profit.begin(), profit.end());
    };
};
