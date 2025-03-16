#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int** links, int n, int k, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;
    for (int i = 0; i < n; i++) {
        if (links[v][i] == 0) {
            continue;
        }
        int u = links[v][i] - 1;
        int hgt = dfs(links, n, k, u, v);
        height_from_leaf = max(height_from_leaf, hgt);
        cut_count += hgt;
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
    scanf("%d %d", &n, &k);
    int* aaa = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aaa[i]);
    }

    int** links = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        links[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 0; j < n + 1; j++) {
            links[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        a--;
        links[a - 1][i] = i + 1;
    }

    int ans = dfs(links, n, k, 0, 0);
    if (aaa[0] != 1) {
        ans += 1;
    }
    printf("%d\n", ans);

    for (int i = 0; i < n; i++) {
        free(links[i]);
    }
    free(links);
    free(aaa);

    return 0;
}
