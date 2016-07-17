#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;



bool match(string& str, int i, string& pat, int j, unordered_set<string>& st, unordered_map<char, string>& mp) 
{
        int strLen = str.length();
        int patternLen = pat.length();
        if(strLen == i && patternLen == j) return true;
    // we are done comparing
        if(strLen == i || patternLen == j) return false;
        
        char CurrentPatternChar = pat[j];
        if (mp.find(CurrentPatternChar)!=mp.end()){
            string patternMapedStr = mp[CurrentPatternChar];
            int patternMapedStrLen = patternMapedStr.length();
            if(patternMapedStr!=str.substr(i,patternMapedStrLen))
                return false;
            return match(str,i+patternMapedStrLen,pat,j+1,st,mp); 
        }
        for(int k = i; k < strLen;k++){
            string s = str.substr(i,k-i+1);
            if(st.find(s)!=st.end()) continue;
            st.insert(s);
            mp[CurrentPatternChar] = s;
            if(match(str,k+1,pat,j+1,st,mp)) return true;
            st.erase(s);
            mp.erase(CurrentPatternChar);
        }
     
        return false;
}

bool wordPatternMatch(string pattern, string str) 
{
    unordered_map<char, string> patternStrMap;
    unordered_set<string> patternSet;

    return match(str, 0, pattern, 0, patternSet,patternStrMap);
}
int main() {
    // Complete the code.
    string s1("abab");
    string s2("redblueredblue");
    //isInterleave(s1,s2,s3);
    cout << wordPatternMatch(s1,s2) << endl;
    return 0;
}

