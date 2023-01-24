#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  double result = 0;
  int i = 0;
  int j = 1;
  while(j < prices.size()) {
    if(prices[j] < prices[i]) {
      i = j;
      j++;
      continue;
    }
    if((prices[j] - prices[i]) > result) {
      result = prices[j] - prices[i];
    }
    j++;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
