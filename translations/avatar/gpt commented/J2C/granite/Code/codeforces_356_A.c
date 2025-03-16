
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

int main() {
    int n;
    scanf("%d", &n);
    set<int> left;
    for (int i = 0; i < n; i++) {
        left.insert(i);
    }
    int q;
    scanf("%d", &q);
    int ans[n];
    memset(ans, 0, sizeof(ans));
    while (q--) {
        int l, r, win;
        scanf("%d%d%d", &l, &r, &win);
        l--;
        r--;
        win--;
        auto it = left.lower_bound(l);
        while (it!= left.end() && *it <= r) {
            ans[*it] = win + 1;
            left.erase(it++);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
