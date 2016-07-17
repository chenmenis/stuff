#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &height1) {

    vector<int> height(height1);
    height.push_back(-1);
    vector<int> index;
    int ret(0);
    for(int i = 0; i < height.size();i++){
         while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    cout << " index.back is out " << index.back() << endl;
                    index.pop_back();

                    int sidx = index.back();//index.size() > 0 ? index.back() : -1;
                    cout << " i " << i << endl;
                    cout << " sidx " << sidx << endl;
                    cout << " (i-sidx-1) " << (i-sidx-1) << endl ;
                    cout <<" h " << h << endl;

                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                }
        cout << " push index" << i << endl;
        index.push_back(i);
    }
    return ret;
}

int main() {
    vector< vector<int>> mat{ {0,1,1,1,1,1},
                              {0,0,1,1,1,1},
                              {0,0,0,1,1,1},
                              {0,0,0,0,0,1}};

    vector<int> curHeight(mat[0].size(),0);

    int cur_max(0);
    for(int row = 0; row < mat.size(); row++){
        for(int col = 0;col < mat[0].size();col++){

             curHeight[col] = mat[row][col] ? ++curHeight[col] : 0;
        }

        for(auto &x: curHeight) cout << x << ",";
        cout << endl;

        cur_max = max(largestRectangleArea(curHeight),cur_max);
        cout << " cur_max " << cur_max << endl;
    }

    vector<int> test1{3,4,5,9,10};
    largestRectangleArea(test1);
    // Complete the code.
    //isInterleave(s1,s2,s3);
   // cout << wordPatternMatch(s1,s2) << endl;
    return 0;
}

