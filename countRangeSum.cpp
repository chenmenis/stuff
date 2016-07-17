#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	void add(vector<int> &fenwick, int n, int x) {
		for (; x < n; x |= x+1)
			fenwick[x]++;
	}
	int getSum(vector<int> &fenwick, int x) {
		int s = 0;
		for (; x; x &= x-1)
			s += fenwick[x-1];
		return s;
	}
	public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int n = nums.size();
		long s = 0, cnt = 0;
		vector<int> fenwick(n+1, 0);
		vector<long> scale;
		scale.push_back(0);
		for (int x: nums)
			scale.push_back(s += x);
		sort(scale.begin(), scale.end());

		for(int x: scale){
            cout << x << " ";
		}

		cout << endl;

		for(int x: scale){
            cout << x << " ";
		}

		s = 0;
		add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), 0) - scale.begin());

		for (int x: nums) {
			s += x;
			int ubound = upper_bound(scale.begin(), scale.end(), s-lower) - scale.begin();
			int lbound = lower_bound(scale.begin(), scale.end(), s-upper) - scale.begin();
			cout << " x " << x << " lbound " << lbound << " ubound " << ubound << endl;
			cnt += getSum(fenwick, ubound) -
				getSum(fenwick,lbound );
			cout <<" getSum(fenwick, ubound) "	<< getSum(fenwick, ubound) <<
                 " getSum(fenwick,lbound ) " << getSum(fenwick,lbound ) << endl;

            cout << " add fenwick "  <<  (lower_bound(scale.begin(), scale.end(), s) - scale.begin()) << " s " << s << endl;
			add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), s) - scale.begin());
		}
		return cnt;
	}
};

int main (){
vector<int> numtest{6,0,-40};

Solution s;
cout << "final " << s.countRangeSum(numtest,5,10) << endl;
return 0;
}
