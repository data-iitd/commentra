
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10000

typedef struct {
    char buf[MAX_LINE_LENGTH];
    int p;
    FILE *r;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->r = stdin;
    s->p = 0;
    return s;
}

char *next(Scanner *s) {
    s->pre(s);
    int start = s->p;
    while (s->p < MAX_LINE_LENGTH && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    s->pre(s);
    int start = s->p;
    while (s->p < MAX_LINE_LENGTH && s->buf[s->p]!= '\n') {
        s->p++;
    }
    char *result = (char *)malloc(s->p - start + 1);
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

int *nextInts(Scanner *s, int n) {
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = nextInt(s);
    }
    return result;
}

long long nextLongLong(Scanner *s) {
    char *token = next(s);
    long long result = atoll(token);
    free(token);
    return result;
}

void pre(Scanner *s) {
    if (s->p >= MAX_LINE_LENGTH) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->p = 0;
    while (1) {
        char c = fgetc(s->r);
        if (c == '\n') {
            break;
        }
        s->buf[s->p] = c;
        s->p++;
    }
}

int main() {
    Scanner *s = newScanner();
    char *N = next(s);
    int n = 0;
    for (int i = 0; N[i]!= '\0'; i++) {
        n += N[i] - '0';
    }
    int m = nextInt(s);
    if (m % n == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    free(N);
    return 0;
}
