#include <stdio.h>
#include <stdlib.h>

void out(int x) {
    printf("%d\n", x);
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, C, K;
    scanf("%d %d %d", &N, &C, &K);
    
    int *t = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }

    qsort(t, N, sizeof(int), cmp);

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
    
    out(ans);
    free(t);
    return 0;
}

// <END-OF-CODE>
