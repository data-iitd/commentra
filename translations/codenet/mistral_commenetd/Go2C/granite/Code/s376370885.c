
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int len;
    int cap;
    int pos;
} Scanner;

Scanner *newScanner(FILE *r) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(1048576);
    s->len = fread(s->buf, 1, 1048576, r);
    s->cap = 1048576;
    s->pos = 0;
    return s;
}

void freeScanner(Scanner *s) {
    free(s->buf);
    free(s);
}

int scanWords(Scanner *s, char **token) {
    int start = s->pos;
    while (s->pos < s->len && isspace(s->buf[s->pos])) {
        s->pos++;
    }
    for (int i = s->pos; i < s->len; i++) {
        if (isspace(s->buf[i])) {
            *token = (char *)malloc(i - start + 1);
            memcpy(*token, s->buf + start, i - start);
            (*token)[i - start] = '\0';
            s->pos = i + 1;
            return 1;
        }
    }
    if (s->pos == s->len) {
        *token = (char *)malloc(s->len - start + 1);
        memcpy(*token, s->buf + start, s->len - start);
        (*token)[s->len - start] = '\0';
        s->pos = s->len;
        return 1;
    }
    return 0;
}

int main() {
    FILE *r = stdin;
    Scanner *s = newScanner(r);
    int n = 0, k = 0;
    char *token;
    while (scanWords(s, &token)) {
        n = atoi(token);
        free(token);
        break;
    }
    while (scanWords(s, &token)) {
        k = atoi(token);
        free(token);
        break;
    }
    freeScanner(s);
    if (n % k == 0) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}
