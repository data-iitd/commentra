#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX
#define LEN (int)(1e6 + 1)

int main() {
    int N;
    long K;
    scanf("%d", &N);
    scanf("%ld", &K);
    
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--; // Adjusting to 0-based index
    }

    int *used = (int *)calloc(N, sizeof(int));
    int *idx = (int *)malloc(N * sizeof(int));
    int *pos = (int *)malloc(N * sizeof(int));
    
    int next = 0, cur = 0;
    while (!used[next]) {
        used[next] = 1;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    long a = (long)cur - idx[next];
    long b = (long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    
    if (b > K) ans = (int)K;
    
    printf("%d\n", pos[ans] + 1); // Adjusting back to 1-based index

    free(A);
    free(used);
    free(idx);
    free(pos);
    
    return 0;
}

// <END-OF-CODE>
