#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start(0);
        int end(0);
        int count(0);
        int maxLenNow(0);
    
        unordered_map<char,int> counterMap;
    
        while(end < s.length()){
            
            if(counterMap[s[end]] ==0){ 
               cout << " counterMap[s[end]] " << counterMap[s[end]] << " s[end] " << s[end] << endl;
                count++;//increase count if this the first occurrence
                
            }  
            counterMap[s[end]]++;
            
            
            while(count > k){ // gone over k distinct char move "start" to a postion where count = k
                
                if(counterMap[s[start++]]--==1){
                    count--;//reduce count if this is the last occurence
                }
            }
            cout << " s[start] " << s[start] <<" start " << start  << " s[end] " << s[end] << " end " << end << endl;
            maxLenNow = max(maxLenNow,end -start+1);
            end++;
        
        }
         cout << " maxLenNow : " << maxLenNow << endl;
        return maxLenNow;
}


int main() {
    // Complete the code.
    
   // maxNumber(list1,list2,4);
    string str = "xkaakjlaabc";
    lengthOfLongestSubstringKDistinct(str,4);
    return 0;
}

