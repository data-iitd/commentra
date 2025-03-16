
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
    int r, d;
    long long x;
    cin >> r >> d >> x;
    for (int i = 0; i < 10; ++i)
    {
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}
// 