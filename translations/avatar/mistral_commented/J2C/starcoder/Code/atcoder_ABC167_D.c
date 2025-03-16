
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int used[N];
    int idx[N];
    int pos[N];
    int next = 0, cur = 0;
    while (used[next] == 0) {
        used[next] = 1;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long a = cur - idx[next];
    long b = idx[next];
    int ans = (int) (10000 * a + K - b + MOD) % a + b;
    if (b > K) {
        ans = (int) K;
    }
    printf("%d\n", pos[ans] + 1);
    return 0;
}

