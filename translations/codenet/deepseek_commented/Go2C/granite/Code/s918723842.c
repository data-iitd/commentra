
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

void freeScanner(Scanner *s) {
    free(s->buf);
    free(s);
}

char *next(Scanner *s) {
    int start = s->p;
    while (s->p < s->size && s->buf[s->p]!='') {
        s->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (s->p - start + 1));
    strncpy(result, s->buf + start, s->p - start);
    result[s->p - start] = '\0';
    s->p++;
    return result;
}

char *nextLine(Scanner *s) {
    int start = s->p;
    while (s->p < s->size) {
        s->p++;
    }
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

long long nextLong(Scanner *s) {
    char *str = next(s);
    long long result = atoll(str);
    free(str);
    return result;
}

double nextDouble(Scanner *s) {
    char *str = next(s);
    double result = atof(str);
    free(str);
    return result;
}

int *nextIntArray(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    int *result = (int *)malloc(sizeof(int) * 1000);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(str);
    return result;
}

long long *nextLongArray(Scanner *s) {
    char *str = next(s);
    char *token = strtok(str, " ");
    long long *result = (long long *)malloc(sizeof(long long) * 1000);
    int i = 0;
    while (token!= NULL) {
        result[i] = atoll(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(str);
    return result;
}

int main() {
    Scanner *s = newScanner();
    int H = nextInt(s);
    int W = nextInt(s);
    int N = nextInt(s);
    int A = H > W? H : W;
    int result = (N + A - 1) / A;
    printf("%d\n", result);
    freeScanner(s);
    return 0;
}

// END-OF-CODE