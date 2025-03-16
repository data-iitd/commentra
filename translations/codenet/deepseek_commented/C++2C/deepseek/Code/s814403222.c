#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    char second[100];
} P;

P v[22];
int d[33][22];
int d_sizes[33];

int compare(const void *a, const void *b) {
    P *p1 = (P *)a;
    P *p2 = (P *)b;
    return p1->first - p2->first;
}

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < 33; i++) d_sizes[i] = 0;
        for (int i = 0; i < n; i++) {
            v[i].first = 0;
            scanf("%s", v[i].second);
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                v[i].first += n - d_sizes[a];
                for (int k = 0; k < d_sizes[a]; k++) {
                    v[d[a][k]].first--;
                }
                d[a][d_sizes[a]++] = i;
            }
        }
        qsort(v, n, sizeof(P), compare);
        printf("%d %s\n", v[0].first, v[0].second);
    }
    return 0;
}
