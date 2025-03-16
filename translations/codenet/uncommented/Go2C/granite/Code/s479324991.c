
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
    pre(s);
    int start = s->p;
    int *result = (int *)malloc(sizeof(int) * 100);
    int count = 0;
    while (s->buf[s->p]!='') {
        if (s->buf[s->p] =='') {
            s->p++;
            continue;
        }
        int v = 0;
        while (s->buf[s->p]!='') {
            v = v * 10 + s->buf[s->p] - '0';
            s->p++;
        }
        result[count] = v;
        count++;
        s->p++;
    }
    int v = 0;
    while (s->buf[s->p]!= '\n') {
        v = v * 10 + s->buf[s->p] - '0';
        s->p++;
    }
    result[count] = v;
    count++;

    return result;
}

int main() {
    Scanner *s = newScanner(stdin);
    int n = nextInt(s);
    int *arr = nextIntArray(s);
    qsort(arr, n, sizeof(int), compare);
    double prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }
    printf("%f\n", prev);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

