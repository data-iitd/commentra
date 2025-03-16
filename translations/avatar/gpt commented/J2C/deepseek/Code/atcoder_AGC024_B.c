#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int P[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        P[i]--; // Adjust for zero-based indexing
    }

    int map[N];
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i; // Map each value to its index
    }

    int nglist[N];
    int nglist_size = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i; // Add the index to the nglist if the order is violated
        }
    }

    if (nglist_size == 0) {
        printf("0\n");
        return 0;
    }

    int ans = nglist[0] + 1 < N - nglist[nglist_size - 1] - 1 ? nglist[0] + 1 : N - nglist[nglist_size - 1] - 1;
    for (int i = 0; i < nglist_size - 1; ++i) {
        int temp = nglist[i] + 1 + N - nglist[i + 1] - 1;
        if (temp < ans) {
            ans = temp;
        }
    }

    printf("%d\n", ans);
    return 0;
}
