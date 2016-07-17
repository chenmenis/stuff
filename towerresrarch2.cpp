#include <iostream>
using namespace std;
int compute(int input){
    int inputval(input);
    if(input < 3) return input;

    int n2 = inputval/2;
    int n3 = inputval/3;
    int n4 = inputval/4;
    int n2p = max(n2,compute(n2));
    int n3p = max(n3,compute(n3));
    int n4p = max(n4,compute(n4));
    int sum = n2p + n3p + n4p;
    return max(input , sum);

}

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testcase(0);
    cin >> testcase;
    while(testcase--){
        int input(0);
        cin >> input;
        int results = compute(input);
        cout << max(0,results - input) << endl;
    }
return 0;
}
