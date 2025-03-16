#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    char second[22];
} P;

P v[22];
int* d[33];

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int m;
        for (int i = 0; i < 33; i++) {
            d[i] = NULL;
        }
        for (int i = 0; i < n; i++) {
            v[i].first = 0;
            scanf("%s %d", v[i].second, &m);
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                v[i].first += n - (d[a] == NULL ? 0 : (int)d[a][0]);
                for (int k = 0; k < (d[a] == NULL ? 0 : (int)d[a][0]); k++) {
                    v[d[a][k]].first--;
                }
                if (d[a] == NULL) {
                    d[a] = (int*)malloc(1 * sizeof(int));
                    d[a][0] = i;
                } else {
                    d[a] = (int*)realloc(d[a], (d[a][0] + 1) * sizeof(int));
                    d[a][d[a][0]] = i;
                }
            }
        }
        // Sorting logic here
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i].first > v[j].first) {
                    P temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
        printf("%d %s\n", v[0].first, v[0].second);
    }
}
