#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

struct Node:
    int x, y, id;

struct Edge:
    int u, v, val;
    bool operator <(const Edge& rhs) const:
        return val < rhs.val;

def findpar(x):
    return par[x] = (par[x] == x ? x : findpar(par[x]));

def unite(x, y):
    x = findpar(x), y = findpar(y);
    if x == y:
        return;
    par[x] = y;

def init():
    for i in range(n + 1):
        par[i] = i;

def main(argc, argv):
    cin >> n;
    init();
    for i in range(1, n + 1):
        scanf("%d%d", &node[i].x, &node[i].y);
        node[i].id = i;
    sort(node + 1, node + n + 1, cmp1);
    cnt = 0;
    for i in range(2, n + 1):
        e[cnt] = (Edge){node[i - 1].id, node[i].id, node[i].x - node[i - 1].x};
        cnt += 1;
    sort(node + 1, node + n + 1, cmp2);
    for i in range(2, n + 1):
        e[cnt] = (Edge){node[i - 1].id, node[i].id, node[i].y - node[i - 1].y};
        cnt += 1;
    sort(e, e + cnt);
    ans = 0;
    for i in range(cnt):
        u = e[i].u;
        v = e[i].v;
        val = e[i].val;
        if findpar(u) == findpar(v):
            continue;
        unite(u, v);
        ans += val;
    print(ans);

if __name__ == "__main__":
    main(int argc, char const *argv[]);

