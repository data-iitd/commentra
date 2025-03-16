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
        s->p = 0;
        fgets(s->buf, MAX_BUFFER_SIZE, stdin);
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
    char *result = malloc(s->p - start + 1);
    strncpy(result, start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

int64_t nextInt64(Scanner *s) {
    char *token = next(s);
    int64_t result = atoll(token);
    free(token);
    return result;
}

double nextFloat(Scanner *s) {
    char *token = next(s);
    double result = atof(token);
    free(token);
    return result;
}

int *nextIntArray(Scanner *s) {
    pre(s);
    int *result = malloc(sizeof(int) * 1000);
    int i = 0;
    while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
        char *start = s->buf + s->p;
        while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
            s->p++;
        }
        char *token = malloc(s->p - start + 1);
        strncpy(token, start, s->p - start);
        token[s->p - start] = '\0';
        result[i++] = atoi(token);
        free(token);
        s->p++;
    }
    return result;
}

int64_t *nextInt64Array(Scanner *s) {
    pre(s);
    int64_t *result = malloc(sizeof(int64_t) * 1000);
    int i = 0;
    while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
        char *start = s->buf + s->p;
        while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
            s->p++;
        }
        char *token = malloc(s->p - start + 1);
        strncpy(token, start, s->p - start);
        token[s->p - start] = '\0';
        result[i++] = atoll(token);
        free(token);
        s->p++;
    }
    return result;
}

int *nextMap(Scanner *s) {
    pre(s);
    int *result = malloc(sizeof(int) * 1000);
    int i = 0;
    while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
        char *start = s->buf + s->p;
        while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
            s->p++;
        }
        char *token = malloc(s->p - start + 1);
        strncpy(token, start, s->p - start);
        token[s->p - start] = '\0';
        result[atoi(token)] = 1;
        free(token);
        s->p++;
    }
    char *start = s->buf + s->p;
    while (s->buf[s->p] != ' ' && s->p < strlen(s->buf)) {
        s->p++;
    }
    char *token = malloc(s->p - start + 1);
    strncpy(token, start, s->p - start);
    token[s->p - start] = '\0';
    result[atoi(token)] = 1;
    free(token);
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

