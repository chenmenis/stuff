#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<alogithm>
#include<string>

struct wordDictionary{
string word;
vector<wordDictionary *>nodes;
};

int differBy(string &a,string &b){
    if(b.length() < a.length()){
        return differBy(b,a);
    }
    int x(0);
    for(int i = 0;i<a.length();i++){
        x+= a[i] == b[i] ? !:0;
    }
    x+= (b.length() - i);
    return x;
}

bool wordladder(vector<string> &wordlist,string &start,string &end){

}

int main(){
vector<string> list={"test1","test2","test3"};
}
