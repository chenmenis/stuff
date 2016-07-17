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

vector<int> findSubstring(string s, vector<string>& words) {

    unordered_map <string,int> dict;

    int wordLen(words[0].size());
    int strLen(words.size()*wordLen);

    for(auto x:words){
        dict[x]++;
    };

    vector<int> res;
    for(int i = 0; i + wordLen <= s.size();){
        unordered_map <string,int> temp_map(dict);
        string subStr = s.substr(i,wordLen);
        cout <<" substring " << subStr  << endl;

        if(temp_map.find(subStr)!=temp_map.end()){

            while(temp_map.find(subStr)!=temp_map.end() && (i + wordLen <= s.size())){
                cout << " i + wordLen " << i + wordLen << " s.size "<< s.size() <<endl;
               cout <<" substring " << subStr << " substr count " << temp_map[subStr] << endl;
                if(!--temp_map[subStr]){
                    cout << "erasing.." << subStr << endl;;
                    temp_map.erase(subStr);
                }
                i += wordLen;
                subStr = s.substr(i,wordLen);

            }
             for ( auto& x: temp_map )
             std::cout << x.first << ": " << x.second << std::endl;



            if(temp_map.empty()){
                cout << " i " << i-strLen << endl;
                res.push_back(i-strLen);
            }
            temp_map = dict;

        } else {

        	i++;
        }
    }
    return res;

}

int main(){
string s("barfoothefoobarman");
vector<string> list{"foo", "bar","man"};
cout << s.substr(0,3) << " " << s.substr(3,3) << endl;

findSubstring(s,list);

return 0;
}
