#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define maxn 100005

typedef struct Node {
    int x, y, id;
}Node;

typedef struct Edge {
    int u, v, val;
}Edge;

Node node[maxn];
Edge e[maxn << 1];
int par[maxn];
int n;

bool cmp1(Node a, Node b) {
    return a.x < b.x;
}

bool cmp2(Node a, Node b) {
    return a.y < b.y;
}

void init() {
    for (int i = 0; i <= n; i ++)
        par[i] = i;
}

int findpar(int x) {
    return par[x] = (par[x] == x? x : findpar(par[x]));
}

void unite(int x, int y) {
    x = findpar(x), y = findpar(y);
    if (x == y) return;
    par[x] = y;
}

int main(int argc, char const *argv[]) {
    
    scanf("%d", &n);

    init();

    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    }

    sort(node + 1, node + n + 1, cmp1);

    int cnt = 0;
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};

    sort(node + 1, node + n + 1, cmp2);
    for (int i = 2; i <= n; i ++)
        e[cnt ++] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};

    sort(e, e + cnt);

    long long ans = 0;
    for (int i = 0; i < cnt; i ++) {
        int u = e[i].u, v = e[i].v, val = e[i].val;
        if (findpar(u) == findpar(v)) continue;
        unite(u, v);
        ans += val;
    }

    printf("%lld\n", ans);

    return 0;
}

