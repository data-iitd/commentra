#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int S, W;
    cin >> S >> W;
    if (S <= W)
        cout << "unsafe";
    else
        cout << "safe";
    return 0;
}

