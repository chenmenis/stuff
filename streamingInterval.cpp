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
#include <deque>


#include <cmath>
using namespace std;


struct interval{

  interval(int x,int y){
      start = x;
      end = y;

  }

  int start;
  int end;
};

bool complow(const interval &a , const interval &b)
{
    cout << a.start << "<" << b.start << endl;
    return a.start < b.start;
}

bool comphi(const interval &a , const interval &b)
{
    return a.start > b.start;
}


class addStreamingIntervals{
    public:
    void insert(int num){

    std::deque<interval>::iterator low,hi;

    low =  std::lower_bound(sortedIntervals.begin(),sortedIntervals.end(),interval(num,num),complow);
    if(low==sortedIntervals.end()) sortedIntervals.push_front(internal(num,num));

    while(it!=sortedIntervals.end()){

    }

    void print (){
        for(interval x:sortedIntervals){
            cout <<"("<< x.start << "," << x.end << ")";
        }
        cout << endl;
    }
    deque<interval> sortedIntervals;
};

int main(){
addStreamingIntervals list1;
list1.insert(3);
list1.print();

list1.insert(1);
list1.print();


 int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 10); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;



return 0;
}
