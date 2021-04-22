//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/



int maxProfit(int* prices, int pricesSize){
int maxP = 0;
    for (int i =1;i<pricesSize;i++)
    {
        if(prices[i]>prices[i-1]){
            maxP += prices[i]-prices[i-1];
        }
    }
    return maxP;
}
