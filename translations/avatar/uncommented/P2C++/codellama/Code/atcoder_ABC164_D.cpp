
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int s, l, a, r, i, e;
    cin >> s >> l;
    int m[2019], m1[2019];
    for (i = 0; i < 2019; i++)
    {
        m[i] = 1;
        m1[i] = 0;
    }
    a = 0;
    r = 0;
    for (i = 0; i < s.length(); i++)
    {
        e = s[i] - '0';
        a += e * pow(10, i, l);
        r += m[a % l];
        m[a % l] += 1;
    }
    cout << r << endl;
    return 0;
}

