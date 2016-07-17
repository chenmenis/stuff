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

int explore(vector< vector<int>> &mat, int row,int col){
     if(!(row >= 0 && row < mat.size() && col >= 0 && col < mat[0].size()))
        return 0;
    
    if(mat[row][col]==1){
     //   cout << " asdf " << endl;
       mat[row][col]= -1;
    //   cout << " row " << row << " col " << col << endl;
       int up = explore(mat,row-1,col);
       int down =  explore(mat,row+1,col);
       int left = explore(mat,row,col-1);
       int right =  explore(mat,row,col+1);
       return 1;
    }
    return 0;
}
int NumOfIslands(vector< vector<int> > &mat){
   
    int rows = mat.size();
    int cols = mat[0].size();
    int islands(0);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cout << " i " << i << endl;
            cout << " j " << j << endl;
            cout << " mat[i][j] " << mat[i][j] << endl;    
            islands+= explore(mat,i,j);
        }
    }
    cout << " islands " << islands << endl;
    return islands;
}


int main() {
    
    vector< vector<int> > islands = {
    {0,1,1,0},
    {0,0,0,1},
    {1,1,1,0},
    {0,0,1,1},
    
    };
    NumOfIslands(islands);
    return 0;
}

