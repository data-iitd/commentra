
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
    char *line = nextLine(s);
    char *token = strtok(line, " ");
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(line);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int n = nextInt(s);
    float *arr = (float *)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (float)nextInt(s);
    }
    qsort(arr, n, sizeof(float), compare);
    float prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }
    printf("%f\n", prev);
    free(arr);
    free(s->buf);
    free(s);
    return 0;
}

