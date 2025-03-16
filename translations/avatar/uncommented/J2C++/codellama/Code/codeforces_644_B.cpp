#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    int n, b;
    long ans[100000];
    queue<long> q;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++)
    {
        int t, d;
        scanf("%d %d", &t, &d);
        while (!q.empty() && q.front() <= t)
        {
            q.pop();
        }
        if (q.size() <= b)
        {
            ans[i] = (q.empty() ? t : q.back()) + d;
            q.push(ans[i]);
        }
        else
        {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%ld ", ans[i]);
    }
    return 0;
}

