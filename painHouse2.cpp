#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

int paintHouse2( vector< vector<int>> &costs){
    int rows = costs.size();
    int cols = costs[0].size();
    int prevMin(0);
    int prevMinIndex(INT_MIN);
    int prevSecondMin(0);
    
    for(int i = 0; i < rows ; i++ ){
        int min(INT_MAX);
        int minIndex(-1);
        int secondMin(min);
        for (int j = 0 ; j < cols ;j++)
        {
            int curVal = ( (j == prevMinIndex ) ? prevSecondMin : prevMin ) + costs[i][j];
            cout << " curVal " << curVal << endl;   
            
            if(min > curVal) {
                secondMin = min;
                min = curVal;
                minIndex = j;
            } else {
                if(secondMin > curVal )
                    secondMin = curVal;
            }
              
        }
        prevMin = min;
        prevMinIndex = minIndex;
        prevSecondMin = secondMin;
        cout << " prevMin " << prevMin << endl;
    }
    return prevMin;
    
}

int main() {
    
    
    vector<int> row1{6,2,5,2,4,7};
    vector<int> row2{6,2,1,7,4,7};
    vector<int> row3{6,2,2,8,4,7};
    vector<int> row4{6,2,4,3,4,7};
    vector<int> row5{6,2,4,4,4,7};
    vector<int> row6{1,2,25,9,4,7};
    vector< vector<int> > mat;
    mat.push_back(row1);
    mat.push_back(row2);
    mat.push_back(row3);
    mat.push_back(row4);
    mat.push_back(row5);
    mat.push_back(row6);
    cout << paintHouse2(mat) << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/
