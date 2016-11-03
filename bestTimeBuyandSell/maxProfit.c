int maxProfit(int *prices, int pricesSize) {
  if (pricesSize == 0 || prices == NULL) return 0;

  int min = prices[0];
  int profit = 0;
  for (int i = 1; i < pricesSize; i++) {
    if (prices[0] < min) {
      min = prices[i];
    } else {
      if ( prices[i] - min > profit) {
        profit= prices[i] - min;
      }
    }
  }
  return profit;
}
