#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
double sortEnvelopeN2(vector<pair<double,double>> &listInput){

    size_t listSize(listInput.size());

    vector<double> dpresult(listSize,1);
    //sort(listInput.begin(),listInput.end());
    double res(0);
    for(int i = 0;i < listSize;i++){
        for(int j = i;j < listSize;j++){
            pair<double,double> &ith = listInput[i];
            pair<double,double> &jth = listInput[j];
            if(ith.first < jth.first && ith.second < jth.second){
                dpresult[j]++;
            } else if(ith.first > jth.first && ith.second > jth.second) {
                dpresult[i]++;
            }

        }
        res = max(dpresult[i],res);
    }


    return res;
}

 int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto comp = [] (const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first<b.first)||(a.first==b.first&&a.second>b.second);
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> tail(envelopes.size()); int tail_size = 0;
    	for (int index=0; index < envelopes.size(); ++index) {
    		int low=0, high=tail_size-1; for (; low <= high; ) {
    			int mid = low + (high - low) / 2;
    			(envelopes[tail[mid]].second < envelopes[index].second)
    			? (low = mid + 1) : (high = mid - 1);
    		}
    		tail[low] = index; (tail_size <= low) && (tail_size = low + 1);
    	}
        return tail_size;
    }

int sortEnvelopeNlogN(vector<pair<int,int>> &listInput){

        auto cmpWithdFirst = [](const pair<int,int> &a, const pair<int,int> &b){
            if( a.first < b.first
               || a.first == b.first && a.second > b.second ) return true;
            return false;
        };

        sort(listInput.begin(),listInput.end(),cmpWithdFirst);

        vector<pair<int,int>> res;

        pair<int,int> current(listInput[0]);

        for(auto x:listInput){

            cout << "("<< x.first << " ," << x.second  << ")," ;
        }

        for(size_t i=1;i<listInput.size();i++){

            if(current.first == listInput[i].first){
                current = listInput[i];
            } else {
                cout << " current first " << current.first << " current second " <<current.second << endl;

                cout << " listInput first " << listInput[i].first << " listInput second " <<listInput[i].second << endl;
                if(current.second < listInput[i].second){
                    res.push_back(current);
                    current = listInput[i];
                }
            }

        }
        res.push_back(current);
        return res.size();

}

int main()
{
    vector<pair<int, int>> myVec = {  {2, 5},{0,0}, {2, 4},{2,3},{1,1},{3,3},{3,7} ,{3,3} };

    cout << maxEnvelopes(myVec) << endl;
    cout << sortEnvelopeNlogN(myVec) << endl;

    cout << "Hello world!" << endl    ;
    return 0;

}



