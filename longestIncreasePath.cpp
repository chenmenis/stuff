#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;

bool checkValid(vector<vector<int>>& matrix,int row,int col, int prevVal){
    if( (row >= matrix.size()) || (row < 0) || ( col < 0) ||(col >= matrix[0].size()) ) return false;
    if( matrix[row][col] > prevVal) return true;
    return false;
}

int longestIncreasingPath(vector<vector<int>>& matrix,int row,int col) {
        
            
        int left(0); 
        int right(0); 
        int up(0); 
        int down(0); 
        int curVal = matrix[row][col];
      //  cout << curVal << endl;
        if(checkValid(matrix,row+1,col,curVal))
        up = 1 + longestIncreasingPath(matrix,row+1,col);
    
        if(checkValid(matrix,row-1,col,curVal))
        down = 1 + longestIncreasingPath(matrix,row-1,col);
    
        if(checkValid(matrix,row,col+1,curVal))
        right = 1 + longestIncreasingPath(matrix,row,col+1);
    
        if(checkValid(matrix,row,col-1,curVal))
        left = 1 + longestIncreasingPath(matrix,row,col-1);
    
        return max(max(max(left,right),up),down);    
     
}

int main() {
    vector< vector<int> > m{{2,3,4,4},{2,5,6,8}};
    cout << longestIncreasingPath(m,0,0) << endl;
    return 0;
}

