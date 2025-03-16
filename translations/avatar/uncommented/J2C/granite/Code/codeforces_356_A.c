
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
    int answer[n];
    for (int i = 0; i < n; i++)
    {
        left.insert(i);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r, win;
        scanf("%d %d %d", &l, &r, &win);
        while (left.upper_bound(l - 1)!= left.end() && *left.upper_bound(l - 1) <= r)
        {
            int curr = *left.upper_bound(l - 1);
            answer[curr] = win;
            left.erase(curr);
        }
        answer[win - 1] = 0;
        left.insert(win - 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", answer[i]);
    }
    printf("\n");
    return 0;
}
