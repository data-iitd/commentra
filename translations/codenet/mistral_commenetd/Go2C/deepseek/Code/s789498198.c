#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF_SIZE 1024

typedef struct {
    char buf[MAX_BUF_SIZE];
    int cur;
} scanner;

void init_scanner(scanner *s) {
    s->cur = 0;
    fgets(s->buf, MAX_BUF_SIZE, stdin);
}

int read_ints(int *a, int *b) {
    scanner s;
    init_scanner(&s);
    char *token = strtok(s.buf, " ");
    if (token == NULL) return 0;
    *a = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) return 0;
    *b = atoi(token);
    return 1;
}

int main() {
    int A, B;
    if (!read_ints(&A, &B)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
    } else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

