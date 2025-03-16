#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX_INT 2147483647
#define LMAX 9223372036854775807
#define LEN 1000001

void doIt() {
    int N;
    long long K;
    int A[LEN];

    scanf("%d %lld", &N, &K);
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

    long long a = (long long) cur - idx[next];
    long long b = (long long) idx[next];
    int ans = (int) ((10000 * a + K - b + MOD) % a + b);

    if (b > K) {
        ans = (int) K;
    }

    printf("%d\n", pos[ans] + 1);
}

int main() {
    doIt();
    return 0;
}

