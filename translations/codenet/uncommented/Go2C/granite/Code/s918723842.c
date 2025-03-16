
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
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->buf = (char *)malloc(sizeof(char) * 1000);
    sc->p = 0;
    sc->size = 1000;
    sc->fp = stdin;
    return sc;
}

char *next(Scanner *sc) {
    int start = sc->p;
    while (sc->p < sc->size && sc->buf[sc->p]!='') {
        sc->p++;
    }
    char *result = (char *)malloc(sizeof(char) * (sc->p - start + 1));
    strncpy(result, sc->buf + start, sc->p - start);
    result[sc->p - start] = '\0';
    sc->p++;
    return result;
}

char *nextLine(Scanner *sc) {
    int start = sc->p;
    sc->p = sc->size;
    char *result = (char *)malloc(sizeof(char) * (sc->p - start + 1));
    strncpy(result, sc->buf + start, sc->p - start);
    result[sc->p - start] = '\0';
    return result;
}

int nextInt(Scanner *sc) {
    char *s = next(sc);
    int result = atoi(s);
    free(s);
    return result;
}

int nextInt64(Scanner *sc) {
    char *s = next(sc);
    long long result = atoll(s);
    free(s);
    return result;
}

float nextFloat(Scanner *sc) {
    char *s = next(sc);
    float result = atof(s);
    free(s);
    return result;
}

int *nextIntArray(Scanner *sc) {
    char *s = next(sc);
    int *result = (int *)malloc(sizeof(int) * 100);
    int i = 0;
    char *token = strtok(s, " ");
    while (token!= NULL) {
        result[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(s);
    return result;
}

int64_t *nextInt64Array(Scanner *sc) {
    char *s = next(sc);
    int64_t *result = (int64_t *)malloc(sizeof(int64_t) * 100);
    int i = 0;
    char *token = strtok(s, " ");
    while (token!= NULL) {
        result[i] = atoll(token);
        i++;
        token = strtok(NULL, " ");
    }
    free(s);
    return result;
}

int main() {
    Scanner *sc = newScanner();
    int H = nextInt(sc);
    int W = nextInt(sc);
    int N = nextInt(sc);
    int A = H > W? H : W;
    int result = (N + A - 1) / A;
    printf("%d\n", result);
    return 0;
}
