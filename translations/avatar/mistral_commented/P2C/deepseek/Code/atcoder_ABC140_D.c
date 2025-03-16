#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main() {
    int N, K;
    char S[100001];
    int seg_cnt[100001] = {0};
    int seg_count = 0;
    int cur_happy = 0;
    int ans = 0;

    // Read the number of segments
    scanf("%d", &N);

    // Read the number of queries
    scanf("%d", &K);

    // Read the string S
    scanf("%s", S);

    // Count the number of segments
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt[seg_count++] = 1;
        }
    }

    // Calculate the current happiness
    cur_happy = N - 1 - (seg_count);

    // Calculate the answer
    if (2 * K >= seg_count) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }

    // Print the answer
    printf("%d\n", ans);

    return 0;
}
