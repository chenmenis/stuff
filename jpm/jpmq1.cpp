#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct rect
{
    rect(int LeftX,int LeftY,int Height,int Width){
        x=LeftX;
        y=LeftY;
        height=Height;
        width=Width;

    }
    int x;
    int y;
    int width;
    int height;
};

bool valueInRange(int value, int min, int max)
{ return (value >= min) && (value <= max); }

bool rectOverlap(rect A, rect B)
{
    bool xOverlap = valueInRange(A.x, B.x, B.x + B.width) ||
                    valueInRange(B.x, A.x, A.x + A.width);

    bool yOverlap = valueInRange(A.y, B.y, B.y + B.height) ||
                    valueInRange(B.y, A.y, A.y + A.height);

    return xOverlap && yOverlap;
}

int main() {

    /*string line;
    while (getline(cin, line)) {
        cout << line << endl;
    }*/

    string line;
    stringstream ss;
    while (getline(cin, line)) {
        stringstream ss(line);

        int firstLeftX;
        int firstLeftY;
        int firstHeight;
        int firstWidth;

        int secondLeftX;
        int secondLeftY;
        int secondHeight;
        int secondWidth;


        ss >> firstLeftX;
        ss >> firstLeftY;
        ss >> firstWidth;
        ss >> firstHeight;

        ss >> secondLeftX;
        ss >> secondLeftY;
        ss >> secondWidth;
        ss >> secondHeight;

        rect A(firstLeftX,firstLeftY,firstWidth,firstHeight);
        rect B(secondLeftX,secondLeftY,secondWidth,secondHeight);

        string s  = rectOverlap(A,B) ? "true" : "false";
        cout << s << endl;
    }

}
