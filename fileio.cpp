#include <fstream>
#include <iostream>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

int main()
{
	string line;

	ifstream myfile( "example.txt" );
	if (myfile)  // same as: if (myfile.good())
	{
		while (getline( myfile, line ))  // same as: while (getline( myfile, line ).good())
		{
            cout << line << endl;
			//if (line == "something")
			{
                int val;
                  std::istringstream iss (line);

                iss >> val;
                cout << val << " >> once " << endl;
                iss >> val;
                cout << val << " >> twice " << endl;

			}
			string input_line;
			 while(cin) {
                getline(cin, input_line);
                cout << input_line << endl;
             };
    return 0;
		}
		myfile.close();
	}
	else cout << "fooey\n";

	return 0;
}
