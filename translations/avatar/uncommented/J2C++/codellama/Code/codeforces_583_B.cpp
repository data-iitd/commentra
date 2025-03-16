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
#include <cassert>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a[n];
        int b[n];
        int s = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = 0;
        }
        int tem = 1;
        int q = 0;
        while (q != n)
        {
            s++;
            if (tem == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i] <= q && b[i] == 0)
                    {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 0;
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    if (a[i] <= q && b[i] == 0)
                    {
                        b[i] = 1;
                        q++;
                    }
                }
                tem = 1;
            }
        }
        cout << s << endl;
    }
    return 0;
}
