#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int recurse(std::unordered_map<string,vector<string> > &knightmap, std::vector<string> &results, string currentstring){

   // cout << currentstring << " " << currentstring.length() << endl;

    if(currentstring.length() >= 7){
        results.push_back(currentstring);
        return 0;
    }
    if(currentstring==""){
        for(int i= 1;i<=9;i++){
            stringstream ss;
            ss << i;
            string str = ss.str();

            recurse(knightmap,results,currentstring+str);
        }
    } else {
       // char *prevchar(currentstring.back());

        string prev = currentstring.substr(currentstring.length()-1);
        cout << " prev " << prev << endl;
        vector<string > childs = knightmap[prev];
        for(string i : childs){
            recurse(knightmap, results, currentstring + i);
        } // access by const reference

    }
    return 0;

}
void setupcheck(){

    //assuming we are only implementing/allowing knight movement
    std::unordered_map<string,vector<string> > knightmap;
    std::vector<string> results;

    vector<string> one;
    one.push_back("6");
    one.push_back("8");

    knightmap["1"]= one;//8183406

    vector<string> two;
    two.push_back("7");
    two.push_back("9");


    knightmap["2"]= two;

    vector<string> three;
    three.push_back("4");
    three.push_back("8");
    knightmap["3"]= three;

    vector<string> four;
    four.push_back("3");
    four.push_back("9");
    four.push_back("0");
    knightmap["4"]= four;

    vector<string> five;
    knightmap["5"]= five;


    vector<string> six;
    six.push_back("1");
    six.push_back("7");
    six.push_back("0");
    knightmap["6"]= six;

    vector<string> seven;
    seven.push_back("2");
    seven.push_back("6");
    knightmap["7"]= seven;

    vector<string> eight;
    eight.push_back("1");
    eight.push_back("3");
    knightmap["8"]= eight;

    vector<string> nine;
    nine.push_back("2");
    nine.push_back("4");
    knightmap["9"]= nine;

    vector<string> zero;
    zero.push_back("4");
    zero.push_back("6");
    knightmap["0"]= zero;

    string startstring ="";

    recurse(knightmap,results,startstring);


  // using default comparison:
  std::vector<string>::iterator it;
  it = std::unique (results.begin(), results.end());
  results.resize( std::distance(results.begin(),it) );
  /*for(string x: results){
        cout << x << endl;
  }*/
  cout << results.size();
  return;
}
using namespace std;
int main() {
    string input("");
    setupcheck();
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
