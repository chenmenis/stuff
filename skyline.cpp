#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
 vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {

        // Step 1: // store/sort by start time
        multimap<int, int> coords;
        for (const vector<int> & building : buildings) {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }
        vector<pair<int,int> > result;
     
        // Step 2:
        multiset<int> heights = { 0 }; // sorted sets
        int prevheight(0);
        map<int, int> corners;
        for (const pair<int, int> & p : coords) {
            if (p.second > 0) {
                cout << " insert hight " << p.second << endl;
                heights.insert(p.second);
            }
            else { // if endtime is encounter remove it from heights sets
                cout << " delete hight " << p.second << endl;
                heights.erase(heights.find(-p.second));
            }
            int cur_y = *heights.rbegin();
            cout << " current back() " << cur_y << endl;
            cout << " p.first " << p.first << " hight " << cur_y << endl;
            if(prevheight!=cur_y){
                corners[p.first] = cur_y;
                pair<int,int> elem(p.first,cur_y);
                result.push_back(elem);
            }
            prevheight = cur_y;
        }
    
     for(pair<int,int> x: result){
         cout << " x , y " << x.first << " , " << x.second << endl;
     }
        // Step 3:
     return result;
        
    }


int main() {
    
    vector<int> one{2,8,5};
    vector<int> two{6,11,8};
    vector<int> three{10,14,4};
    
    vector< vector<int> > list;
    list.push_back(one);
    list.push_back(two);
    list.push_back(three);
    getSkyline(list);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

