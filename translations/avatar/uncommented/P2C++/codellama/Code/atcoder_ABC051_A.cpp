
#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    cout << str;
    return 0;
}

