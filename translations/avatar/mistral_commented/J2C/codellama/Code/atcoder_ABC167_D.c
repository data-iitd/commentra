
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX
#define len 1000001

void doIt() {
    int N, K, A[len], i, next, cur, idx[len], pos[len];
    bool used[len];

    scanf("%d", &N);
    scanf("%ld", &K);

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }

    memset(used, false, sizeof(used));
    next = 0;
    cur = 0;

    while (!used[next]) {
        used[next] = true;
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
}

int main() {
    doIt();
    return 0;
}

