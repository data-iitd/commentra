#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *buf;
    int cur;
    FILE *r;
} scanner;

void init_scanner(scanner *s) {
    s->buf = (int *)malloc(100 * sizeof(int));
    s->cur = 0;
    s->r = stdin;
}

void readln(scanner *s) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, s->r)) != -1) {
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL) {
            s->buf[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }
    s->cur = 0;
    free(line);
}

int isFull(scanner *s) {
    return s->cur == 100;
}

void resetCur(scanner *s) {
    s->cur = 0;
}

int nextInt(scanner *s) {
    if (s->cur == 0) {
        readln(s);
    }
    int res = s->buf[s->cur++];
    if (isFull(s)) {
        resetCur(s);
    }
    return res;
}

int nextInts(scanner *s, int *arr, int size) {
    readln(s);
    for (int i = 0; i < size; i++) {
        arr[i] = s->buf[i];
    }
    resetCur(s);
    return size;
}

int main() {
    scanner s;
    init_scanner(&s);

    int A = nextInt(&s);
    int B = nextInt(&s);

    if ((A + B) % 2 == 0) {
        printf("%d\n", (A + B) / 2);
        return 0;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}

