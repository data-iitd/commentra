
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct {
    char *buf;
    int p;
} Scanner;

void pre(Scanner *s) {
    if (s->p >= strlen(s->buf)) {
        s->buf = realloc(s->buf, MAX_BUFFER_SIZE);
        fgets(s->buf, MAX_BUFFER_SIZE, stdin);
        s->p = 0;
    }
}

char *next(Scanner *s) {
    pre(s);
    char *start = s->buf + s->p;
    while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
        s->p++;
    }
    char *result = malloc(s->p - start + 1);
    strncpy(result, start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    pre(s);
    char *start = s->buf + s->p;
    s->p = strlen(s->buf);
    return start;
}

int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int64_t nextInt64(Scanner *s) {
    char *str = next(s);
    int64_t result = atoll(str);
    free(str);
    return result;
}

double nextFloat(Scanner *s) {
    char *str = next(s);
    double result = atof(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s, int *size) {
    pre(s);
    char *start = s->buf + s->p;
    int *result = malloc(sizeof(int) * 1000);
    int i = 0;
    while (s->p < strlen(s->buf)) {
        if (s->buf[s->p] == ' ' || s->p == strlen(s->buf)) {
            char *str = malloc(s->p - start + 1);
            strncpy(str, start, s->p - start);
            str[s->p - start] = '\0';
            result[i++] = atoi(str);
            free(str);
            start = s->buf + s->p + 1;
        }
        s->p++;
    }
    *size = i;
    return result;
}

int64_t *nextInt64Array(Scanner *s, int *size) {
    pre(s);
    char *start = s->buf + s->p;
    int64_t *result = malloc(sizeof(int64_t) * 1000);
    int i = 0;
    while (s->p < strlen(s->buf)) {
        if (s->buf[s->p] == ' ' || s->p == strlen(s->buf)) {
            char *str = malloc(s->p - start + 1);
            strncpy(str, start, s->p - start);
            str[s->p - start] = '\0';
            result[i++] = atoll(str);
            free(str);
            start = s->buf + s->p + 1;
        }
        s->p++;
    }
    *size = i;
    return result;
}

int *nextMap(Scanner *s) {
    pre(s);
    char *start = s->buf + s->p;
    int *result = malloc(sizeof(int) * 1000);
    int i = 0;
    while (s->p < strlen(s->buf)) {
        if (s->buf[s->p] == ' ' || s->p == strlen(s->buf)) {
            char *str = malloc(s->p - start + 1);
            strncpy(str, start, s->p - start);
            str[s->p - start] = '\0';
            result[i++] = atoi(str);
            free(str);
            start = s->buf + s->p + 1;
        }
        s->p++;
    }
    return result;
}

int main() {
    Scanner *sc = malloc(sizeof(Scanner));
    sc->buf = malloc(MAX_BUFFER_SIZE);
    sc->p = 0;
    fgets(sc->buf, MAX_BUFFER_SIZE, stdin);
    int A = nextInt(sc);
    int B = nextInt(sc);
    int mx = max(A + B, A - B);
    mx = max(mx, A * B);
    printf("%d\n", mx);
    return 0;
}

int max(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

