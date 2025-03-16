
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int P[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        --P[i];
    }
    int map[N];
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }
    int nglist[N];
    int nglist_size = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[nglist_size++] = i;
        }
    }
    if (nglist_size == 0) {
        printf("0\n");
        return 0;
    }
    int ans = N - nglist[0] - 1;
    for (int i = 0; i < nglist_size - 1; ++i) {
        ans = ans < nglist[i] + 1 + N - nglist[i + 1] - 1? ans : nglist[i] + 1 + N - nglist[i + 1] - 1;
    }
    printf("%d\n", ans);
    return 0;
}
