#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>
#include <string>

#include <cmath>

int main() {
    shortestPalindrome2("aa1234");
    return 0;
}

string shortestPalindrome2(string s) {
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());
	string l = s + "#" + rev_s;

	vector<int> p(l.size(), 0);

	for (int i = 1,j=0; i < l.size(); i++) {
		cout << " l[i] " << l[i] << " i " << i << " l[j] " << l[j] << " j " << j << endl; 
		if(l[i]==l[j]){
			p[i] = p[i-1]+1;
			j++;
		} else {
			while(j > 0 && l[i] != l[j]){

				j = p[j-1];
			} 

			p[i] = l[i]==l[j] ? (1+p[j++]):0;
		}
	}
	for (auto x : p){
		cout << x << ",";
	}
	cout << endl;     
	cout << p[l.size() - 1] << endl;
	return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
}

