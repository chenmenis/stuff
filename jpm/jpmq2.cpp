#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    stringstream ss;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n(0);
        while(ss >>n){
        cout << n << ",";
        }
        cout << endl;
    }

/*vector<int> v;
    istringstream is( s );
    int n;
    while( is >> n ) {
    	v.push_back( n );
    }
    return v.size();*/
}
