
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

char *next(Scanner *s) {
    s->p = 0;
    while (s->buf[s->p]!='' && s->buf[s->p]!= '\0') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p + 1));
    strncpy(result, s->buf, s->p);
    result[s->p] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    s->p = 0;
    while (s->buf[s->p]!= '\n' && s->buf[s->p]!= '\0') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p + 1));
    strncpy(result, s->buf, s->p);
    result[s->p] = '\0';
    s->p++;
    return result;
}

int nextInt(Scanner *s) {
    char *str = next(s);
    int result = atoi(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(str);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int n = nextInt(s);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = nextInt(s);
        ans += 1.0 / tmp;
    }
    printf("%f\n", 1.0 / ans);
    return 0;
}
