
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int h, a, num;
    string str;
    cin >> str;
    stringstream ss(str);
    ss >> h >> a;
    num = 0;
    for (int i = 1; h > 0; i++)
    {
        h = h - a;
        num++;
    }
    cout << num << endl;
    return 0;
}

