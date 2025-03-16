
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *buf;
    int p;
    int size;
    FILE *r;
} Scanner;

Scanner *NewScanner() {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->r = stdin;
    s->buf = (char *)malloc(sizeof(char) * 1000);
    s->p = 0;
    s->size = 1000;
    return s;
}

char *Next(Scanner *s) {
    s->pre(s);
    int start = s->p;
    for (; s->p < s->size; s->p++) {
        if (s->buf[s->p] =='') {
            break;
        }
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *NextLine(Scanner *s) {
    s->pre(s);
    int start = s->p;
    s->p = s->size;
    char *result = (char *)malloc(sizeof(char) * (s->p - start));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    return result;
}

int NextInt(Scanner *s) {
    char *token = Next(s);
    int result = atoi(token);
    free(token);
    return result;
}

int *NextIntArray(Scanner *s) {
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    char *token = Next(s);
    while (token[0]!= '\0') {
        result[i] = atoi(token);
        i++;
        token = Next(s);
    }
    return result;
}

void pre(Scanner *s) {
    if (s->p >= s->size) {
        s->readLine(s);
        s->p = 0;
    }
}

void readLine(Scanner *s) {
    s->buf = (char *)realloc(s->buf, sizeof(char) * (s->size * 2));
    s->size *= 2;
    int c;
    int i = 0;
    while ((c = fgetc(s->r))!= EOF) {
        s->buf[i] = (char)c;
        i++;
    }
    s->buf[i] = '\0';
}

int main() {
    Scanner *sc = NewScanner();
    int n = NextInt(sc);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = NextInt(sc);
    }
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

