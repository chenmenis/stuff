
#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>

using namespace std;

int dungeon(vector< vector<int>> &grid){
    
    int cols(grid[0].size());
    int rows(grid.size());
    
    int dp[rows][cols];
    
    
    for(int i = rows-1;i >= 0;i--){
        for(int j = cols -1;j >=0;j--){
            if (i == rows -1 && j == cols -1){
                dp[rows-1][cols-1] = max(1 - grid[rows-1][cols-1],1);
            }
            else if(i == rows -1){
                dp[i][j] = max(dp[i][j+1] - grid[i][j],1);               
            } else if(j == cols -1 ){
                dp[i][j] = max(dp[i+1][j] - grid[i][j],1);
            } else {
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - grid[i][j],1);
            }

        }
    }
   
    for(int i = 0;i < rows ; i++){
        for(int j = 0; j < cols;j++){
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    
    return dp[0][0];
}


int main() {
    vector< vector<int> > m{{-2,-4},
                            {-2,-8}};
    
    dungeon(m);
    
    return 0;
}

