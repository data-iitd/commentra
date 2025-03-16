

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char value;
    int len;
} Block;

int main() {
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);
    char S[N + 1];
    scanf("%s", S);

    Block *blocks = RunLength(S, N);

    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < N; r++) {
        sum += blocks[r].len;
        if (blocks[r].value == '0') {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].len;
            if (blocks[l].value == '0') {
                zero--;
            }
            l++;
        }
        ans = fmax(ans, sum);
    }
    printf("%d\n", ans);

    return 0;
}

Block *RunLength(char *s, int N) {
    Block *r = (Block *)malloc(sizeof(Block) * N);
    if (N == 0) {
        return r;
    }
    Block t = {s[0], 1};
    for (int i = 1; i < N; i++) {
        if (t.value == s[i]) {
            t.len++;
        } else {
            r[i - 1] = t;
            t = (Block){s[i], 1};
        }
    }
    r[N - 1] = t;
    return r;
}

// 