
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(1000 * sizeof(char));
    s->p = 0;
    return s;
}

char *next(Scanner *s) {
    s->pre(s);
    int start = s->p;
    while (s->p < strlen(s->buf) && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    s->pre(s);
    int start = s->p;
    while (s->p < strlen(s->buf) && s->buf[s->p]!= '\n') {
        s->p++;
    }
    char *result = (char *)malloc((s->p - start + 1) * sizeof(char));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int v = atoi(token);
    free(token);
    return v;
}

int64_t nextInt64(Scanner *s) {
    char *token = next(s);
    int64_t v = atoll(token);
    free(token);
    return v;
}

float nextFloat(Scanner *s) {
    char *token = next(s);
    float v = atof(token);
    free(token);
    return v;
}

int *nextIntArray(Scanner *s) {
    char *line = nextLine(s);
    char **tokens = strsplit(line, " ");
    int n = strlen(tokens);
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = atoi(tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return result;
}

int64_t *nextInt64Array(Scanner *s) {
    char *line = nextLine(s);
    char **tokens = strsplit(line, " ");
    int n = strlen(tokens);
    int64_t *result = (int64_t *)malloc(n * sizeof(int64_t));
    for (int i = 0; i < n; i++) {
        result[i] = atoll(tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
    return result;
}

void pre(Scanner *s) {
    if (s->p >= strlen(s->buf)) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    char *line = (char *)malloc(1000 * sizeof(char));
    fgets(line, 1000, stdin);
    s->buf = (char *)realloc(s->buf, strlen(s->buf) + strlen(line) + 1);
    strcat(s->buf, line);
    free(line);
}

char **strsplit(char *str, char *delim) {
    char **tokens = (char **)malloc(100 * sizeof(char *));
    int n = 0;
    char *token = strtok(str, delim);
    while (token!= NULL) {
        tokens[n] = (char *)malloc(strlen(token) + 1);
        strcpy(tokens[n], token);
        n++;
        token = strtok(NULL, delim);
    }
    tokens[n] = NULL;
    return tokens;
}

