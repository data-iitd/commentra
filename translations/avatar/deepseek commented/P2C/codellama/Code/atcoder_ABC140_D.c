#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int gi() {
    char *data = malloc(1000000);
    scanf("%s", data);
    int result = atoi(data);
    free(data);
    return result;
}

char *gw() {
    char *data = malloc(1000000);
    scanf("%s", data);
    return data;
}

int main() {
    int N = gi();
    int K = gi();
    char *S = gw();

    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }

    int cur_happy = N - 1 - seg_cnt;

    if (2 * K >= seg_cnt) {
        printf("%d", N - 1);
    } else {
        printf("%d", cur_happy + 2 * K);
    }

    return 0;
}

