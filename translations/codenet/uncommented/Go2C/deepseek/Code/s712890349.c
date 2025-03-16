#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Value[2];
    int Len;
} Block;

Block* RunLength(const char* s, int* len) {
    Block* r = (Block*)malloc(*len * sizeof(Block));
    if (*len == 0) {
        return r;
    }
    Block t = {.Value = s[0], .Len = 1};
    int index = 0;
    for (int i = 1; i < *len; i++) {
        if (strcmp(t.Value, s + i) == 0) {
            t.Len++;
        } else {
            r[index++] = t;
            t = (Block){.Value = s + i, .Len = 1};
        }
    }
    r[index++] = t;
    *len = index;
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
    int len;
    Block* blocks = RunLength(S, &len);
    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < len; r++) {
        sum += blocks[r].Len;
        if (strcmp(blocks[r].Value, "0") == 0) {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].Len;
            if (strcmp(blocks[l].Value, "0") == 0) {
                zero--;
            }
            l++;
        }
        ans = Max(ans, sum);
    }
    printf("%d\n", ans);
    free(blocks);
    return 0;
}

