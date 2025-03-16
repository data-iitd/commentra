#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *Value;
    int Len;
} Block;

Block* RunLength(const char *s, int *size) {
    int len = strlen(s);
    Block *r = malloc(len * sizeof(Block));
    *size = 0;

    if (len == 0) {
        return r;
    }

    r[*size].Value = malloc(2 * sizeof(char));
    r[*size].Value[0] = s[0];
    r[*size].Value[1] = '\0';
    r[*size].Len = 1;
    (*size)++;

    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            r[*size - 1].Len++;
        } else {
            r[*size].Value = malloc(2 * sizeof(char));
            r[*size].Value[0] = s[i];
            r[*size].Value[1] = '\0';
            r[*size].Len = 1;
            (*size)++;
        }
    }
    return r;
}

int Max(int a, int b) {
    return (b > a) ? b : a;
}

int main() {
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);
    char S[1000001];
    scanf("%s", S);

    int size;
    Block *blocks = RunLength(S, &size);
    int sum = 0, zero = 0, l = 0;

    for (int r = 0; r < size; r++) {
        sum += blocks[r].Len;
        if (blocks[r].Value[0] == '0') {
            zero++;
        }
        while (zero > K) {
            sum -= blocks[l].Len;
            if (blocks[l].Value[0] == '0') {
                zero--;
            }
            l++;
        }
        ans = Max(ans, sum);
    }

    printf("%d\n", ans);

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(blocks[i].Value);
    }
    free(blocks);

    return 0;
}

// <END-OF-CODE>
