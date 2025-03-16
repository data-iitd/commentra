#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX INT_MAX
#define LMAX LONG_MAX
#define LEN 1000001

void doIt(void) {
    int N, A[LEN];
    long K;
    scanf("%d %ld", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }
    bool used[LEN] = {false};
    int idx[LEN], pos[LEN];
    int next = 0, cur = 0;
    while (!used[next]) {
        used[next] = true;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long a = (long)(cur - idx[next]);
    long b = (long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if (b > K) ans = (int)K;
    printf("%d\n", pos[ans] + 1);
}

int main(void) {
    doIt();
    return 0;
}
