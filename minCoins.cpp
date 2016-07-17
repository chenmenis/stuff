#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>
#include <string>
#include <sstream>


#include <cmath>
using namespace std;

void coinsMin(vector<int> coinsList, int target){
    

    std::vector<int> TotalCounts(target+1,INT_MAX);
    TotalCounts[0] = 0;
    std::vector<int> CoinTrails(target+1,-1);
    
    for(int i = 0; i < coinsList.size();i++){
        for(int t = 1; t <= target;t++ ){
            if(t >= coinsList[i]) {
                if(TotalCounts[t - coinsList[i]] + 1 < TotalCounts[t]){
                    TotalCounts[t]= TotalCounts[t - coinsList[i]] + 1;
                    CoinTrails[t]=i;
                }  
            }
        }
    }
    cout << "total:" << TotalCounts[target]; 
    int start = target;
    while(start){
        cout << "CoinTrails[start]:" << coinsList[CoinTrails[start]] << endl;
        start = start - coinsList[CoinTrails[start]];
    }
}


int main() {
    vector<int> list1{4,5,0,9};
    vector<int> list2{1,3,4,8,7};
    coinsMin(list2,15);

    return 0;
}

