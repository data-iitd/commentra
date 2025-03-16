
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string input_array;
    int result = 0;
    getline(cin, input_array);
    stringstream ss(input_array);
    string str;
    while (ss >> str)
    {
        result++;
        if (str == "0")
            break;
    }
    cout << result << endl;
    return 0;
}

