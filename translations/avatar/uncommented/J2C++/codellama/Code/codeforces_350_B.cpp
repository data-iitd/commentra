
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <ctime>
#include <cassert>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int b[n + 1];
    int num[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        num[b[i]]++;
    string ss = "";
    int ans = 0;
    bool st[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            st[i] = true;
            stringstream sb;
            int x = b[i];
            stringstream sss;
            sss << i;
            sb << " " << sss.str().c_str();
            int s = 1;
            while (!st[x] && num[x] == 1 && x != 0 && a[x] != 1)
            {
                sss.str("");
                sss << x;
                sb << " " << sss.str().c_str();
                st[x] = true;
                x = b[x];
                s++;
            }
            if (s > ans)
            {
                ans = s;
                ss = sb.str().c_str();
            }
        }
    }
    cout << ans << endl;
    cout << ss << endl;
    return 0;
}

