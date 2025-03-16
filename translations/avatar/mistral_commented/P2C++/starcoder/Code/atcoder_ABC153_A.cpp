
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int h, a, sho, am;
    cin >> h >> a;
    sho = h / a;
    am = h % a;
    if (am!= 0)
    {
        sho += 1;
    }
    cout << sho << endl;
    return 0;
}

