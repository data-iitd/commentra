#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <utility>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 0)
    {
        if (m != 0)
            cout << "Impossible" << endl;
        else
            cout << 0 << " " << 0 << endl;
        return 0;
    }
    if (m <= n)
    {
        if (m == 0)
            m = 1;
        cout << n << " " << (m + n - 1) << endl;
        return 0;
    }
    cout << m << " " << (m + n - 1) << endl;
    return 0;
}

