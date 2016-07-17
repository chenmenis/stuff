#include <iostream>
#include <unordered_map>

using namespace std;
int  compute(int  inputval, std::unordered_map<int,int> &mymap){
    if(inputval < 3) return inputval;

    int n2 = inputval/2;
    int n3 = inputval/3;
    int n4 = inputval/4;

    int n2p(0);
    if(mymap.find(n2) != mymap.end()){
        n2p = mymap[n2];
    } else {
        n2p = max(n2,compute(n2, mymap));
        mymap[n2] = n2p;
    }

    int n3p(0);

    if(mymap.find(n3) != mymap.end()){
        n3p = mymap[n3];
    } else {
        n3p = max(n3,compute(n3, mymap));
        mymap[n3] = n3p;
    }


    int n4p(0);

    if(mymap.find(n4) != mymap.end()){
        n4p = mymap[n4];
    } else {
        n4p = max(n4,compute(n4, mymap));
        mymap[n4] = n4p;
    }
    //int n3p = max(n3,compute(n3,mymap));
    //int n4p = max(n4,compute(n4,mymap));
    int sum = n2p + n3p + n4p;
    return max(inputval , sum);

}

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::unordered_map<int,int> mymap;
    int  testcase(0);
    cin >> testcase;
    while(testcase--){
        int  input(0);
        cin >> input;
        int results = compute(input,  mymap);
        cout << max(0,results - input )<< endl;
    }
return 0;
}
