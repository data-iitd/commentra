#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        P[i]--; // Adjusting to 0-based index
    }

    int *map = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    int *nglist = (int *)malloc((N - 1) * sizeof(int));
    int nglist_size = 0;

    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i;
        }
    }

    if (nglist_size == 0) {
        printf("0\n");
        free(P);
        free(map);
        free(nglist);
        return 0;
    }

    int ans = (N - nglist[0] - 1 < nglist[nglist_size - 1] + 1) ? (N - nglist[0] - 1) : (nglist[nglist_size - 1] + 1);

    for (int i = 0; i < nglist_size - 1; ++i) {
        int temp = nglist[i] + 1 + N - nglist[i + 1] - 1;
        if (temp < ans) {
            ans = temp;
        }
    }

    printf("%d\n", ans);

    free(P);
    free(map);
    free(nglist);
    return 0;
}
