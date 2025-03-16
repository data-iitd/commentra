
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct Scanner {
    char *buf;
    int p;
    int len;
} Scanner;

Scanner *NewScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
    s->p = 0;
    s->len = 0;
    return s;
}

void pre(Scanner *s) {
    if (s->p >= s->len) {
        s->len = readLine(s->buf, MAX_BUFFER_SIZE);
        s->p = 0;
    }
}

int readLine(char *buf, int size) {
    int i = 0;
    char c = getchar();
    while (c != '\n' && i < size) {
        buf[i++] = c;
        c = getchar();
    }
    buf[i] = '\0';
    return i;
}

char *next(Scanner *s) {
    pre(s);
    char *start = s->buf + s->p;
    while (s->buf[s->p] != ' ' && s->p < s->len) {
        s->p++;
    }
    s->buf[s->p++] = '\0';
    return start;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    return atoi(token);
}

int nextIntArray(Scanner *s, int *arr, int size) {
    char *line = nextLine(s);
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < size) {
        arr[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return i;
}

char *nextLine(Scanner *s) {
    pre(s);
    char *start = s->buf + s->p;
    while (s->buf[s->p] != '\n' && s->p < s->len) {
        s->p++;
    }
    s->buf[s->p++] = '\0';
    return start;
}

int main() {
    Scanner *sc = NewScanner();
    int H = nextInt(sc);
    int W = nextInt(sc);
    int N = nextInt(sc);
    int A = H > W ? H : W;
    printf("%d\n", (N + A - 1) / A);
    return 0;
}

