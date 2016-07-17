#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool isGoodMove(int x, int y, vector< vector<int> > &maze,int max_x,int max_y){

	return x >= 0 && y >= 0 && x < max_x && y < max_y && maze[x][y]==1;
}

bool getMeOut(int x, int y, vector < vector<int> > &maze , vector< vector<int> > &sol,int max_x,int max_y, int dest_x, int dest_y,int prev_x, int prev_y){
	if(x == dest_x && dest_y == y) {
		sol[x][y] = 1;
		return true;
	}
	if(isGoodMove(x,y,maze, max_x,max_y)){
		sol[x][y] = 1;
		if( (x+1) != prev_x){
			if( getMeOut(x+1,y,maze,sol,max_x,max_y,dest_x,dest_y,x,y))
				return true;
		}
		if( (y+1) != prev_y){
			if( getMeOut(x,y+1,maze,sol,max_x,max_y,dest_x,dest_y,x,y))
				return true;
		}
		if( (x-1) != prev_x){
			if( getMeOut(x-1,y,maze,sol,max_x,max_y,dest_x,dest_y,x,y))
				return true;
		}
		if( (y-1) != prev_y){
			if( getMeOut(x,y-1,maze,sol,max_x,max_y,dest_x,dest_y,x,y))
				return true;
		}
		sol[x][y] = 0;
	}
	return false;
}

int bestRouteToPrincess(int x, int y, vector < vector<int> > &maze , vector< vector<int> > &sol,int max_x,int max_y, int dest_x, int dest_y){
	if(x == dest_x && dest_y == y) {
		sol[x][y] = 1;
		return maze[x][y];
	}
	int bloodCostNow = maze[x][y];
	int go_right(0);
	int go_down(0);
	if(x + 1 < max_x) {
		go_right =  bestRouteToPrincess(x+1,y,maze,sol,max_x,max_y,dest_x,dest_y);
	}
	if(y + 1 < max_y){
		go_down =   bestRouteToPrincess(x,y+1,maze,sol,max_x,max_y,dest_x,dest_y);
	}

	int cheapest(0);
	if( x+ 1 < max_x && y+1 < max_y){       
		cheapest= max(go_right,go_down);
		if(cheapest == go_right){
			sol[x+1][y] = 1;
		} else {
			sol[x][y+1] = 1;
		}
	} else {

		if(x + 1 < max_x ){
			cheapest = go_right;
			sol[x+1][y] = 1;
		} else {
			cheapest = go_down;
			sol[x][y+1] = 1;
		}
	}
	return bloodCostNow + min(cheapest,0);
}
int testDungeonRun(){
	int intArray2d[5][5]={
		{0,0,-1,0,0},
		{0,0,-1,0,0},
		{0,-1,-1,-1,4},
		{-1,-1,0,-1,-1},
		{0,0,0,-1,-5}

	};
	int rows =  sizeof(intArray2d)/ sizeof(intArray2d[0]); // 2 rows  
	int cols = sizeof (intArray2d[0]) / sizeof(int); // 5 cols

	vector< vector<int> > sol(rows,vector<int>(cols));
	vector< vector<int> > input(rows,vector<int>(cols));

	for(int i =0; i < rows;i++){
		for(int j = 0; j < cols;j++){
			sol[i][j]=0;
			input[i][j] = intArray2d[i][j];
			std::cout << input[i][j] << ",";
		}
		std::cout << std::endl;
	}
	std::cout << " dim is row " << rows << " col " << cols << std::endl;
	int start_i = 0;
	int start_j = 0;
	int dest_i = rows-1;
	int dest_j = cols-1;
	int cost = bestRouteToPrincess(start_i,start_j,input,sol,rows,cols,dest_i,dest_j);

	for(int i =0; i < rows;i++){
		for(int j = 0; j < cols;j++){
			std::cout << sol[i][j] << ",";
		}
		std::cout << std::endl;
	}
	std::cout << " cost is : " << cost  << std::endl;
	return 0;
}
int testMaze(){
	int intArray2d[5][5]={
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,1,1,1,0},
		{1,1,0,1,1},
		{0,0,0,1,0}

	};
	///
	int rows =  sizeof(intArray2d)/ sizeof(intArray2d[0]); // 2 rows  
	int cols = sizeof (intArray2d[0]) / sizeof(int); // 5 cols

	vector< vector<int> > sol(rows,vector<int>(cols));
	vector< vector<int> > input(rows,vector<int>(cols));

	for(int i =0; i < rows;i++){
		for(int j = 0; j < cols;j++){
			sol[i][j]=0;
			input[i][j] = intArray2d[i][j];
			std::cout << input[i][j] << ",";
		}
		std::cout << std::endl;
	}

	std::cout << " dim is row " << rows << " col " << cols << std::endl;
	int start_i = 0;
	int start_j = 2;
	int dest_i = 3;
	int dest_j = 0;
	if(!getMeOut(start_i,start_j,input,sol,rows,cols,dest_i,dest_j,-1,-1)){
		std::cout << " no solution " << std::endl;
	}

	for(int i =0; i < rows;i++){
		for(int j = 0; j < cols;j++){
			std::cout << sol[i][j] << ",";
		}
		std::cout << std::endl;
	}
	return 0;

}

int giveMeMyCoin(int inputNum, vector<int> &input,bool isListSorted){

	for (size_t i = 0 ; i < input.size();i++){
		int curr_number_input = inputNum;
		curr_number_input -= input[i];
		for(int j = i+1;j< input.size();j++){
			if(isListSorted && curr_number_input < input[j]) return -1;
			if(curr_number_input == input[j]){
				std::cout << " first num : " << inputNum - curr_number_input << " second_num : "  << curr_number_input << std::endl;
				return j;
			}
		}
	}
	return -1;
}
int testMyCoin(){
	int s [] = {-2,2,3,3,3,4,5,6,9,39 };
	int list_size =  sizeof(s)/ sizeof(s[0]); // 2 rows  
	vector<int> list(list_size);
	for(size_t i = 0; i < list.size();i++){
		list[i] = s[i];
	}
	int input = 1;
	
	int idx = giveMeMyCoin(input,list,true);
	if(idx < 0) {cout << "nothing available.." << endl;}
	else { 
		std::cout << " first num : " << input - list[idx] << " second_num : "  << list[idx] << std::endl;
	
	}


	return 0;
}
int main(int argc, char * argv[]){
//	testMaze();
//	testMyCoin();
	testDungeonRun();
	return 0;
}
