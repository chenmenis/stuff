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
using namespace std;

vector< vector<char> > decodeMat(string s,int row,int col){
    string s1("");//("6_r2_4_brbrbr_3b2rb_b2r2br_r2b3rb");
    s1 = s;
    cout << s1 << endl;
    string res;
    for(int i = 0 ;i < s1.length();){
        int k(0);

        while(isdigit(s1[i])){
            //char cur(s1[i]);
            stringstream newstr(s1.substr(i++,1));
            int digit;
            newstr >> digit ;
            k = !k ? (digit):k*10+(digit);

        }

        char x = s1[i++];
        if(x == 'r'||x == 'b'||x == '_'){
            cout << " k: " << k << endl;
            std::string str(!k?1:k, x);
            cout << " str " << str << endl;
            res.append(str);
        } else {
            cout << " not a valid char" << endl;
            //some error handling
        }
    }
   // cout << " concatted str " << res << endl;
    vector< vector<char> >  mat(row, vector<char>(col,'.'));

    int stri=0;
    for(int row=0; row < mat.size();row++)
    {
        for(int col=0; col < mat[0].size();col++){
            mat[row][col] = res[stri++];
            cout << mat[row][col] << ",";
        }
        cout << endl;
    }
    return mat;

}

int main() {
    decodeMat("5_r2_4_brbrbr",6,7);
    return 0;
}

