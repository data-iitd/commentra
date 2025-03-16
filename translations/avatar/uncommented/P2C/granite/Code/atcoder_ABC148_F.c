
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int n, ta, ao;
vector<int> g[100005];
int ta_dist[100005];
int ao_dist[100005];

void ta_dfs(int node) {
    for (int i = 0; i < g[node].size(); i++) {
        int v = g[node][i];
        if (ta_dist[v]!= -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v);
    }
}

void ao_dfs(int node) {
    for (int i = 0; i < g[node].size(); i++) {
        int v = g[node][i];
        if (ao_dist[v]!= -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v);
    }
}

int main() {
    scanf("%d%d%d", &n, &ta, &ao);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(ta_dist, -1, sizeof(ta_dist));
    memset(ao_dist, -1, sizeof(ao_dist));
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;
    ta_dfs(ta);
    ao_dfs(ao);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (ta_dist[i] > ao_dist[i]) continue;
        res = max(res, ao_dist[i]);
    }
    printf("%d\n", res - 1);
    return 0;
}
