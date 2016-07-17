#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int>> matrix;

matrix matrixmul(matrix &a,matrix &b){
	int rowsize = a.size();
	int colsize = b[0].size();
	matrix c(rowsize,vector<int>(colsize,0));
	//A*B
	for(int k = 0;k < b[0].size();k++){
		for(int row = 0;row < a.size(); row++){
			int sum(0);
			for(int j = 0; j < a[row].size();j++){
				sum+=a[row][j]*b[j][k];
			}
			c[row][k] = sum;
		}
	}
	return c;

}

matrix pow(matrix &m, int nth_power){
	if(nth_power==1) return m;
	if(nth_power==2) return matrixmul(m,m);
	if(nth_power % 2 == 1){
        matrix m_1 = pow(m,nth_power-1);
		return matrixmul( m,m_1);
	} else {
		return pow(m,nth_power/2);
	}
}

int calcFib(int n) {// fibanachi
    vector<vector<int> > mtrix(2,vector<int>(2,0));
    mtrix[0][0] = 1;
    mtrix[0][1] = 1;
    mtrix[1][1] = 1;
    mtrix[1][0] = 0;
    matrix m = pow(mtrix,n);
	return m[0][1];
}
int calcTrib(int n) {
    vector<vector<int> > mtrix(3,vector<int>(3,0));
    mtrix[0][0] = 1;
    mtrix[0][1] = 1;
    mtrix[0][2] = 1;
    mtrix[1][0] = 1;
    mtrix[2][1] = 1;
    matrix m = pow(mtrix,n);
	return m[1][0];
}

int main(){
return 0;
}
