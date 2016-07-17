#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,i,k;
    cin>>N>>M;
    //assert(3<=N);
    //assert(N<=10000000);
    //assert(1<=M);
    //assert(M<=200000);
    vector < pair<int, pair<  int ,   int > > > V;
    for(i=1 ; i<=M ; i++)
    {
        int a,b;
        cin>>a>>b>>k;
        V.push_back(make_pair(a,make_pair(-1,k)));
        V.push_back(make_pair(b,make_pair(1,k)));
    }
    sort(V.begin(), V.end());
    
    int tmp(0);
    int ret(0);
    for (int i = 0; i<V.size(); i++)
	{
		if (V[i].second.first == -1)
			tmp += V[i].second.second;
		else
			tmp -= V[i].second.second;

		if (tmp > ret)
			ret = tmp;
	}
    
    //for(i=0 ; i<2*M; i++)
    //    A[i] = V[i].second;
    //for(i=1 ; i<2*M ; i++)
    //    A[i] = A[i-1]+A[i];
    //sort(A,A+2*M);
    //cout<<A[2*M -1]<<endl;
    //return 0;
    cout << ret << endl;
    return 0;
}
