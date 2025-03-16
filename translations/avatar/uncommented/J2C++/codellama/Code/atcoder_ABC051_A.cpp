
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string a;
    getline(cin, a);
    stringstream ss(a);
    string b;
    while (ss >> b)
    {
        cout << b << " ";
    }
    cout << endl;
    return 0;
}
