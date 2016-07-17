#include<iostream>
#include<vector>
#include<algorithm>


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>

#include <algorithm>
using namespace std;


int main() {
    int i;
    cin >> i;
    while(i--){
        int j;
        cin >> j;
        vector<int> list;
        while(j--){
            int k(0);
            cin >> k;
            list.push_back(k);
            cout << k << endl;
        }
    }


    string STRING;
	ifstream infile;
	infile.open ("names.txt");
    while(!infile.eof()) // To get you all the lines.
    {
        getline(infile,STRING); // Saves the line in STRING.
	    cout<<STRING << endl; // Prints our STRING.
    }
	infile.close();


//    vector< vector<int> > matrix;
//    int rows = matrix.size();
//    int cols = matrix[0].size();
/*
    for(int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            for(int i = row; i < rows;i++) {
                for(int j = col; j < cols;j++) {
                        int sum(0);


                    for(int row_c = row; row_c < i;row_c++){
                        for(int col_c = col;col_c < j;col_c++){
                           sum+= matrix[row_c][col_c];
                        }
                    }


                }
            }
        }
    } */
cout << 4/ 5 << endl;
    return 0;
}
