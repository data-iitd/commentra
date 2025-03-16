
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    int N, C, K;
    scanf("%d %d %d", &N, &C, &K);
    int t[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, N, sizeof(int), cmpfunc);
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K;
    for (int i = 1; i < N; i++) {
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            cnt = 1;
            end = t[i] + K;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

