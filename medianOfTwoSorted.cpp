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

int findKthElements(vector<int> &list1,vector<int> &list2,int list1Ind,int list2Ind,int list1Size,int list2Size,int k){

    cout << "list1Size " << list1Size << " list2Size " << list2Size << " k " << k << endl;

    if(list2Size < list1Size){
      return  findKthElements(list2,list1,list2Ind,list1Ind,list2Size,list1Size,k);
    }
    if(list1Size == 0 && list2Size > 0 ){
        return list2[list2Ind+k-1];
    }

    if (k==1) return min(list1[list1Ind],list2[list2Ind]);

    int i = min(list1Size,k/2);
    int j = min(list2Size,k/2);

    cout << " list1[i-1] " <<list1[i-1] << " list2[j-1] " << list2[j-1]<< endl;
   // cout << " list1[i-2] " < <list1[i-1] << endl;

    if(list1[list1Ind+i-1] < list2[list2Ind+j-1]) {//already find the ith element
       return findKthElements(list1,list2,i+list1Ind,list2Ind,list1Size -i,j, k-i);
    }
    else //if (list1[i] > list2[j]) //already find the jth element
    {
       return findKthElements(list1,list2,list1Ind,j+list2Ind,i,list2Size-j,k-j);

    }
    return list1[list1Ind+i-1];
}


int medianOfTwoSortedArrays(vector<int> &list1,vector<int> &list2){
    cout << ceil((list1.size()+list2.size())*1.0/2) << endl;
   cout << "result "<< findKthElements(list1,list2,0,0,list1.size(),list2.size(),(int)ceil((list1.size()+list2.size())*1.0/2) ) << endl;
    return 0;
}



int main() {
  vector< vector<int> > islands = {
    {0,1,1,0},
    {0,0,0,1},
    {1,1,1,0},
    {0,0,1,1},

    };
    vector<int> slist2{1,2,3,9};
    vector<int> slist1{1,2,4,5,9};
    medianOfTwoSortedArrays(slist1,slist2);
  //  NumOfIslands(islands);
    return 0;
}
