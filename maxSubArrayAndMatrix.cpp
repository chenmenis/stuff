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

void maxSubArray(vector<int> list, int &maxNum, int &gstart,int &gend){
    vector<int> sumArray(list.size(),0);
    sumArray[0] =list[0];
    int globalMax(0);
    gstart = 0;
    gend = 0;
    for(int i=1;i <list.size();i++){
        int begin=gstart,end=gend;
        
         if(list[i] > sumArray[i-1]+list[i]){
            sumArray[i] = list[i];
            begin = end =i;
             
        } else {
           sumArray[i] =  sumArray[i-1]+list[i];
           end = i;
        }
        if(globalMax < sumArray[i]){
            globalMax = sumArray[i];
            gstart = begin;
            gend = end;
                
        }
    }
    
    cout << " global Max " << globalMax << endl;
    cout << " globalstart " << gstart << endl;
    cout << " globalend " << gend << endl;
    maxNum =  globalMax;
    return;
    
}

int maxSubMat(vector< vector<int> > &mat){
    int maxNum(INT_MIN);
    int maxTop;
    int maxBottom;
    int maxLeft;
    int maxRight;
    for(int k=0; k < mat[0].size();k++){
        vector<int> cumsumCol(mat.size(),0);
        
        for(int i=k;i < mat[0].size();i++){
               
            for(int j=0;j<mat.size();j++)
                cumsumCol[j]+=mat[j][i];
            int newMax;
            int newTop;
            int newBottom;
            maxSubArray(cumsumCol,newMax,newTop,newBottom);
            cout << " oldMax" << maxNum <<endl; 
            cout << " newMax" << newMax <<endl; 

            if(maxNum < newMax){
                cout << " oldMax" << maxNum <<endl; 
                maxNum = newMax;
                maxTop = newTop;
                maxBottom = newBottom;
                maxRight = i;
                maxLeft = k;
                cout << " newMax " << newMax << " maxTop " << newTop << " maxBottom "<< newBottom << " newLeft " << maxLeft << " maxRight " << maxRight << endl;
            }
        } 

    }
    return maxNum;
    
}
int main() {
    // Complete the code.
    string s1("abab");
    string s2("redblueredblue");
    vector<int> s{8,7,5,4,3,2};
  //  largestRectangleArea(s);
   // vector<int> jmp{1,2,5,4,3,2,3,4,2,1,4,5,6,8,2};
   // jump2(jmp);
    //isInterleave(s1,s2,s3);
   // cout << wordPatternMatch(s1,s2) << endl;
   // string sf("ADOBECODEBANC");
   // string sub("ABC");
   //cout << minWindow(sf,sub) << endl;
    //vector<int> prices{1,2,5,4,3,2,3,4,2,1,4,5,6,8,2};
    //maxStockProfit(prices,2);
    vector< vector<int> > m{{-2,-4},
                            {-2,-8}};
    cout << longestIncreasingPath(m,0,0) << endl;
    vector<int> ballons{1,2,3};
    //burstBallons(ballons);
    
   // dungeon(m);
    vector<int> list1{4,5,0,9,-10};
    vector<int> list2{1,3,4,8,7};
   // vector<int> a(merge(list1,list2,list1.size()+list2.size()));
    
   // maxNumber(list1,list2,4);
    string str = "xkaakjlaabc";
   // lengthOfLongestSubstringKDistinct(str,4);
    //shortestPalindrome2("aa1234");
    //shortestPalindrome("aa1234");
//     longestPalindrome("aba");
    //coinsMin(list2,15);
   // permuteString("aabcd");
    
    int start,end,maxNum;    
    maxSubArray(list1,maxNum,start,end);
    vector< vector<int> > mat = {
    {-3,5,-4,-3},
    {1,3,4,-5},
    {1,3,4,5},
    {1,-3,-4,-5},
    
    };
    maxSubMat(mat);
    return 0;
}

