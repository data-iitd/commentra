#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string a;
    cin >> a;
    cout << (a.find("1") == string::npos ? 0 : pow(2, a.substr(a.find("1") + 1).size() - 1));
    return 0;
}



