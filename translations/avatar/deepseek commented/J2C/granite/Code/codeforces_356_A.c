
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    set<int> left;
    for (int i = 0; i < n; i++)
    {
        left.insert(i);
    }
    int q;
    scanf("%d", &q);
    int answer[n];
    memset(answer, 0, sizeof(answer));
    while (q--)
    {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        l--;
        r--;
        win--;
        auto it = left.lower_bound(l);
        while (it!= left.end() && *it <= r)
        {
            answer[*it] = win;
            left.erase(it);
            it = left.lower_bound(l);
        }
        answer[win] = 0;
        left.insert(win);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", answer[i]);
    }
    printf("\n");
    return 0;
}
