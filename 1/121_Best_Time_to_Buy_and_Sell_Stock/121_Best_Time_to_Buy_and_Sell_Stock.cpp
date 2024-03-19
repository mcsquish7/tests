#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - min_price);
            min_price = min(prices[i], min_price);
        }

        return profit;
    }
};

int main()
{
    vector<int> prices = {1};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}