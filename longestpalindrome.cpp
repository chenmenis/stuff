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

int longestPalindrome(string s) {
     string pre="^#";
     string post="$";
     string newstr="";
    if (s.length()<2) return 1;
     
    newstr+=pre;
    
    for(auto x:s) newstr=newstr+x+"#";
    newstr= newstr+ post;
    vector<int> p(newstr.length(),0);
    cout << s << endl;
    cout << newstr << endl;
    
    for(int i=1,center=0,right=0;i<newstr.length();i++){
        int mirror_i = center*2-i;
    //    cout <<" newstr[i] " << newstr[i] << " right " << right << " i " << i << "  mirror_i " << mirror_i << " center " << center  << endl;
        p[i] = right > i ? min(p[mirror_i],right - i):0;
     //   cout << " newstr[i+p[i]+1] " << newstr[i+p[i]+1] << "  newstr[i-p[i]-1] " << newstr[i-p[i]-1] << " for add 1 to " << newstr[i] << endl;
        while(newstr[i+p[i]+1]==newstr[i-p[i]-1]) {
         cout << " i+p[i]+1 " << i+p[i]+1 << " newstr[i+p[i]+1] " << newstr[i+p[i]+1] << " i-p[i]-1 " << i-p[i]-1 << "  newstr[i-p[i]-1] " << newstr[i-p[i]-1] << " for add 1 to " << newstr[i] << endl;   
         p[i]++;
         
        }
        
        
        
        if(i+p[i] > right){
            center = i;
            right = i+p[i];
        }
    }
    for(auto x:newstr) cout << x << ",";
        cout << endl;
  
    for(auto x:p) cout << x << ",";
        cout << endl;
    
    cout << " max " << *std::max_element(p.begin(),p.end()) << endl;  
    return 0;
} 


int main() {
     longestPalindrome("aba");
    return 0;
}

