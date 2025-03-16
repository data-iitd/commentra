#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

int *par, *rank;

void initialize(int n) {
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

int root(int i) {
    if (par[i] == i) return i;
    par[i] = root(par[i]);
    return par[i];
}

int same(int i, int j) {
    return root(i) == root(j);
}

void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return;
    if (rank[i] < rank[j]) {
        par[i] = j;
    } else {
        par[j] = i;
        if (rank[i] == rank[j]) rank[i]++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--; // Adjusting to 0-based index
    }

    initialize(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        unite(x - 1, y - 1); // Adjusting to 0-based index
    }

    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) {
            s++;
        }
    }

    printf("%d\n", s);

    free(par);
    free(rank);
    free(p);
    
    return 0;
}
// <END-OF-CODE>
