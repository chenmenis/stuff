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

void permuteUtility(vector<char> &chars, vector<int> &counts,vector<char> &results,int level){
    if(level==results.size()){
        for(auto x:results)
               cout << x << ",";
        
        cout  << "done" << endl;
    }
    
    for(int nonZero=0;nonZero < counts.size();nonZero++){
        if(counts[nonZero]==0) continue;
        results[level] = chars[nonZero];
        counts[nonZero]--;

        permuteUtility(chars,counts,results,level+1);
        counts[nonZero]++;
    }
}


void permuteString(string s){
    unordered_map<char,int> map;
    vector<char> chars;
    vector<int> counts;
    
    for(char x:s){
        if(map.find(x)!=map.end()){
            map[x]++;
        }
        else { map[x] = 1; }
    }
    cout << " asdf s" << endl;

    int index =0;
    for ( auto it = map.begin(); it != map.end(); ++it )
    {
        chars.push_back((char)it->first); 
        counts.push_back( (int)it->second);
        
    }
    
    vector<char> results(s.length());
    permuteUtility(chars,counts,results,0);
    
}

int main() {
    permuteString("aabcd");
    return 0;
}

