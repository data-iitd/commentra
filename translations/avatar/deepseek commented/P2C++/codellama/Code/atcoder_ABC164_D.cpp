
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    int l = 2019;
    cin >> s;
    int m[l + 1] = { 1 }, a = 0, r = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a += (s[i] - '0') * pow(10, i, l);
        r += m[a % l];
        m[a % l]++;
    }
    cout << r << endl;
    return 0;
}

