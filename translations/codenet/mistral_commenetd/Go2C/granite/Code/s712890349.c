
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char value;
    int len;
} Block;

int Max(int a, int b) {
    return (b > a)? b : a;
}

Block* RunLength(char* s) {
    if (strlen(s) == 0) {
        return NULL;
    }

    Block* t = (Block*)malloc(sizeof(Block));
    t->value = s[0];
    t->len = 1;

    Block* r = (Block*)malloc(sizeof(Block));
    r[0] = *t;

    for (int i = 1; s[i]!= '\0'; i++) {
        if (t->value == s[i]) {
            t->len++;
        } else {
            r = (Block*)realloc(r, (i + 1) * sizeof(Block));
            r[i] = *t;
            t = (Block*)malloc(sizeof(Block));
            t->value = s[i];
            t->len = 1;
        }
    }

    r = (Block*)realloc(r, (strlen(s) + 1) * sizeof(Block));
    r[strlen(s)] = *t;

    return r;
}

int main() {
    int N, K, ans = 0;
    scanf("%d %d", &N, &K);

    char* s = (char*)malloc(N * sizeof(char));
    fgets(s, N, stdin);
    s[strlen(s) - 1] = '\0';

    Block* blocks = RunLength(s);

    int sum = 0, zero = 0, l = 0;
    for (int r = 0; r < strlen(blocks); r++) {
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
        ans = Max(ans, sum);
    }

    printf("%d\n", ans);

    return 0;
}

