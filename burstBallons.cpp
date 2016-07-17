#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>

using namespace std;

int burstBallons(vector<int> &ballons){
    
    vector<int> dp(ballons.size()+2,0);
    dp[0] = dp[ballons.size()-1] = 1;
    for(int i = 1 ; i <  dp.size() -1 ;i++) dp[i] = ballons[i-1];//padding ends
    for(int i =0;i < dp.size();i++) cout << dp[i] <<",";
    cout << endl;
    
    int dpmatrix[dp.size()][dp.size()];
    memset(dpmatrix, 0, sizeof(int)*dp.size()*dp.size());  

    cout << " size " << dp.size() << endl;
    for(int k = 2;k< dp.size();k++){
        cout << " k: " << k << endl;
        for(int left = 0;left + k < dp.size();left++){
            int right = left + k;
            cout << " computing from left " << left << " right " << right << endl;
            for(int i = left+1;i < right;i++){
               cout << " dpmatrix[left][right] " << dpmatrix[left][right] << " dpmatrix[left][i] " << dpmatrix[left][i] << " dpmatrix[i][right] " << dpmatrix[i][right] << " i "<< i << " dp[i] " << dp[i] << " dp[left] " << dp[left] << " dp[right] " << dp[right]  << endl; 
                dpmatrix[left][right] = max(dpmatrix[left][right],dpmatrix[left][i]+dpmatrix[i][right]+dp[i]*dp[left]*dp[right]);
                cout << " dpmatrix[left][right]  " << dpmatrix[left][right]  << endl;
            }
        }
        
    }
    cout << " dpmatrix: " << dpmatrix[0][dp.size()-1] << endl; 
    return dpmatrix[0][dp.size()-1];
}


int main() {

    vector<int> ballons{1,2,3};
    
    return 0;
}

