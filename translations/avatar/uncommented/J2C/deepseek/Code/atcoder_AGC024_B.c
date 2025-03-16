#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    scanf("%d", &N);
    int P[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
        P[i]--; // Convert to 0-based index
    }

    int map[N];
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    int nglist[N];
    int ngcount = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (map[i] > map[i + 1]) {
            nglist[ngcount++] = i;
        }
    }

    if (ngcount == 0) {
        printf("0\n");
        return 0;
    }

    int ans = INT_MAX;
    ans = (N - nglist[0] - 1) < ans ? (N - nglist[0] - 1) : ans;
    ans = (nglist[ngcount - 1] + 1) < ans ? (nglist[ngcount - 1] + 1) : ans;

    for (int i = 0; i < ngcount - 1; ++i) {
        int temp = nglist[i] + 1 + (N - nglist[i + 1] - 1);
        ans = temp < ans ? temp : ans;
    }

    printf("%d\n", ans);
    return 0;
}

