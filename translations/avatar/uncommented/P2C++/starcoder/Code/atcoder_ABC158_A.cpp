#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.find("A")!= string::npos && s.find("B")!= string::npos)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
