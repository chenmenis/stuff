#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;
int maxStockProfit(vector<int> priceOrig, int k){

    vector< vector<int> > dp (k+1, vector<int>(priceOrig.size()+1,0));
    int maxglobal(0);

    vector<int> prices(priceOrig.size()+1);

    copy(priceOrig.begin(),priceOrig.end(),prices.begin()+1);

    for(int trans = 1 ; trans <= k; trans++){
        for(int day = 1; day <= priceOrig.size(); day++) {
            int todaysPrice = prices[day];
            int maxVal(0);
            for(int m=1;m < day;m++){
              maxVal  = max(max(todaysPrice -prices[m] +dp[trans-1][m],maxVal),dp[trans][m]);
              cout << " maxVal " << maxVal << " todaysPrice -prices[m] +dp[trans-1][m] " << todaysPrice -prices[m] +dp[trans-1][m] << " todaysPrice -prices[m]  " << todaysPrice -prices[m]  << " dp[trans][m] " << dp[trans][m] << endl;

            }
            dp[trans][day] = maxVal;
            maxglobal = max(maxglobal,dp[trans][day]);

            cout << " maxglobal " << maxglobal << endl;

        }

    }

    return maxglobal;

}
int main() {
    // Complete the code.
    vector<int> prices{1,2,5,4,3,2,3,4,2,1,4,5,6,8,2};
    maxStockProfit(prices,2);

    return 0;
}

