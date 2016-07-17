#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int longestValidParenthesis(string s){

	stack<int> lstack;
	vector<int> dp(s.length(),0);

	int len=0;

	for(int i = 0;i < s.length();i++){
		if(s[i] == '('){
			lstack.push(i);
			dp[i] =dp[i?i-1:0];
		}else if(s[i] == ')'){
			if(lstack.size()>0){
				int index = lstack.top();
				int matchedLen = (i - index)+1;
				lstack.pop();
				cout << " index -1 " << index -1 << endl;
				dp[i] = ((index -1 >= 0)? dp[index -1]:0 )+ matchedLen;
			} else {
				dp[i] =dp[i?i-1:0];
			}
		}
	}
    for( auto &x:dp) {
        cout << x << ",";
    }
    cout << endl;
	return dp[s.length()-1];
}

int main(){
longestValidParenthesis(")(");

return 0;
}
