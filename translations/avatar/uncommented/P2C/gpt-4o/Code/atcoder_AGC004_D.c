#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000000

int dfs(int **links, int n, int k, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;

    for (int i = 0; links[v][i] != -1; i++) {
        int u = links[v][i];
        if (u == 0) {
            continue;
        }
        int hgt, cut;
        int result = dfs(links, n, k, u, v);
        hgt = result >> 16; // Extract height
        cut = result & 0xFFFF; // Extract cut count
        height_from_leaf = (hgt > height_from_leaf) ? hgt : height_from_leaf;
        cut_count += cut;
    }
    height_from_leaf += 1;

    if (p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    return (height_from_leaf << 16) | cut_count; // Combine height and cut count
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *aaa = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &aaa[i]);
        aaa[i]--; // Convert to 0-based index
    }

    int **links = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        links[i] = (int *)malloc((n + 1) * sizeof(int)); // Allocate space for links
        for (int j = 0; j < n + 1; j++) {
            links[i][j] = -1; // Initialize with -1 to mark end of links
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int a = aaa[i];
        links[a][i] = i + 1; // Store the link
    }

    int ans = dfs(links, n, k, 0, 0) & 0xFFFF; // Get cut count
    if (aaa[0] != 1) {
        ans += 1;
    }
    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(links[i]);
    }
    free(links);
    free(aaa);

    return 0;
}

// <END-OF-CODE>
