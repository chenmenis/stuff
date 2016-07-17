#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &height) {

    vector<int> index;
    int ret(0);
    for(int i = 0; i < height.size();i++){
         while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();

                    int sidx = index.size() > 0 ? index.back() : -1;
                    cout << h << endl;
                    cout << " sidx " << sidx << endl;
                    cout << " (i-sidx-1) " << (i-sidx-1) << endl ;  
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                } 
        cout << " push index" << i << endl;
        index.push_back(i);
    }
    return ret;
}

int main() {
    // Complete the code.
    string s1("abab");
    string s2("redblueredblue");
    vector<int> s{8,7,5,4,3,2};
    largestRectangleArea(s);
    //isInterleave(s1,s2,s3);
   // cout << wordPatternMatch(s1,s2) << endl;
    return 0;
}

