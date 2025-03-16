
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *fp;
} Scanner;

Scanner *newScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    s->fp = stdin;
    return s;
}

void pre(Scanner *s) {
    if (s->p >= s->size) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->p = 0;
    char *buf = (char *)malloc(sizeof(char) * 1000);
    fgets(buf, 1000, s->fp);
    s->buf = (char *)realloc(s->buf, sizeof(char) * (strlen(buf) + 1));
    strcpy(s->buf, buf);
    free(buf);
}

char *next(Scanner *s) {
    pre(s);
    int start = s->p;
    while (s->buf[s->p]!='' && s->buf[s->p]!= '\0') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    pre(s);
    int start = s->p;
    while (s->buf[s->p]!= '\n' && s->buf[s->p]!= '\0') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

int nextInt(Scanner *s) {
    char *token = next(s);
    int result = atoi(token);
    free(token);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *tokens = next(s);
    char *token = tokens;
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (*token!= '\0') {
        if (*token =='') {
            *token = '\0';
            result[i] = atoi(token + 1);
            token = token + 1;
            i++;
        }
        token++;
    }
    result[i] = atoi(token);
    free(tokens);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int n = nextInt(s);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = 1 / nextInt(s);
        ans += tmp;
    }
    printf("%v\n", 1 / ans);
    return 0;
}

// END-OF-CODE