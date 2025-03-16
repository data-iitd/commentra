
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

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int oo = 1e9;

int n;
vector<int> g[MAXN];

int maxMatching(int v, int p) {
    int a = 0, o = 0;
    for (int w : g[v]) {
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + min(1, o) + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m = maxMatching(1, -1) / 2;
    printf("%s\n", 2 * m == n? "Second" : "First");
    return 0;
}

