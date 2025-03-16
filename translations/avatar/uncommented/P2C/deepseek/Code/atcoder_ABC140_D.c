#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int N, K;
char S[100005];

int main() {
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    int cur_happy = N - 1 - seg_cnt;
    int ans;
    if (2 * K >= seg_cnt) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }

    printf("%d\n", ans);
    return 0;
}

