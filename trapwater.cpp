#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;
int trapWater(vector<int> &tiles){
    int rightStart = tiles.size()-1;
    int leftStart = 0;
    int currentMaxheight(0);
    int area(0);

    while(leftStart < rightStart){
        if(tiles[leftStart] > tiles[rightStart]){
           currentMaxheight = max(tiles[rightStart],currentMaxheight);
            area += currentMaxheight - tiles[rightStart];
            cout << "currentMaxheight - tiles[rightStart];" << currentMaxheight << " - " << tiles[rightStart] << " area " << area << endl;
            rightStart--;
        } else {
            currentMaxheight = max(tiles[leftStart],currentMaxheight);
            area += currentMaxheight - tiles[leftStart];
            cout << "currentMaxheight - tiles[leftStart];" << currentMaxheight << " - " << tiles[leftStart] << " area " << area << endl;
            leftStart++;
        }

    }
    return area;


}
int main() {

    vector<int> tiles{6,2,4,9,4,7};
    trapWater(tiles);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

