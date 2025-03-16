#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int** links, int n, int k, int* aaa, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;
    for (int i = 0; i < n; i++) {
        if (links[v][i] == 0) continue;
        int hgt = dfs(links, n, k, aaa, links[v][i], v);
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += 1;
    }
    height_from_leaf += 1;
    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    return height_from_leaf;
}

int main() {
    int n, k;
    int aaa[MAX_N];
    int* links[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        links[i] = (int*)malloc(MAX_N * sizeof(int));
    }

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &aaa[i]);
        aaa[i]--;
        for (int j = 0; j < n; j++) {
            scanf("%d", &links[i][j]);
            if (links[i][j] == -1) break;
            links[i][j]--;
        }
    }

    int ans = dfs(links, n, k, aaa, 0, 0);
    if (aaa[0] != 1) {
        ans += 1;
    }
    printf("%d\n", ans);

    for (int i = 0; i < MAX_N; i++) {
        free(links[i]);
    }
    return 0;
}
