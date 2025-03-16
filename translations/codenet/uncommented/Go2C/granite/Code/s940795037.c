
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *fp;
} Scanner;

Scanner *newScanner(FILE *fp) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    s->fp = fp;
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
    char c;
    while ((c = fgetc(s->fp))!= '\n') {
        s->buf[s->p] = c;
        s->p++;
        if (s->p >= s->size) {
            s->size *= 2;
            s->buf = (char *)realloc(s->buf, sizeof(char) * s->size);
        }
    }
    s->buf[s->p] = '\0';
}

char *next(Scanner *s) {
    pre(s);
    int start = s->p;
    while (s->buf[s->p]!='') {
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
    s->p = s->size;
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
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
    FILE *fp = fopen("input.txt", "r");
    Scanner *s = newScanner(fp);
    int n = nextInt(s);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int tmp = 1 / nextInt(s);
        ans += tmp;
    }
    printf("%v\n", 1 / ans);
    fclose(fp);
    return 0;
}

