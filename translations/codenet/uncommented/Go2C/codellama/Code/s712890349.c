#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *Value;
    int Len;
} Block;

int main() {
    int N, K, ans, sum, zero, l;
    scanf("%d %d", &N, &K);
    char *S;
    S = (char *)malloc(1000000 * sizeof(char));
    scanf("%s", S);
    Block *blocks = RunLength(S);
    sum = 0;
    zero = 0;
    l = 0;
    for (int r = 0; r < N; r++) {
        sum += blocks[r].Len;
        if (blocks[r].Value == '0') {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == '0') {
                zero--;
            }
            l++;
        }
        ans = sum > ans ? sum : ans;
    }
    printf("%d\n", ans);
    return 0;
}

Block *RunLength(char *s) {
    int i, j, len;
    Block *r;
    len = strlen(s);
    r = (Block *)malloc(len * sizeof(Block));
    r[0].Value = (char *)malloc(2 * sizeof(char));
    r[0].Value[0] = s[0];
    r[0].Value[1] = '\0';
    r[0].Len = 1;
    for (i = 1; i < len; i++) {
        if (r[i - 1].Value[0] == s[i]) {
            r[i - 1].Len++;
        } else {
            r[i].Value = (char *)malloc(2 * sizeof(char));
            r[i].Value[0] = s[i];
            r[i].Value[1] = '\0';
            r[i].Len = 1;
        }
    }
    return r;
}

