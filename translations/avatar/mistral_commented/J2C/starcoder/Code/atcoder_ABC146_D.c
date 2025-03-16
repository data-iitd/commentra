
#include <stdio.h>
#include <stdlib.h>

int n;
int ans[100000];

struct Edge {
 int id, to;
};

struct Edge edges[100000];

void dfs(int to, int color, int parents) {
 int k = 1;
 for (int i = 0; i < n; i++) {
 if (edges[i].to == parents) continue;
 if (k == color) k++;
 ans[edges[i].id] = k;
 dfs(edges[i].to, k, to);
 k++;
 }
}

int main() {
 scanf("%d", &n);
 for (int i = 0; i < n - 1; i++) {
 int a, b;
 scanf("%d %d", &a, &b);
 edges[i].id = i;
 edges[i].to = b - 1;
 edges[i + n - 1].id = i + n - 1;
 edges[i + n - 1].to = a - 1;
 }
 dfs(0, -1, -1);
 int max = 0;
 for (int i = 0; i < n - 1; i++) {
 max = max > ans[i]? max : ans[i];
 }
 printf("%d\n", max);
 for (int i = 0; i < n - 1; i++) {
 printf("%d\n", ans[i]);
 }
 return 0;
}

