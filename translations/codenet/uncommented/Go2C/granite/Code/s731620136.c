
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char buf[10240];
    char *ptr;
} Scanner;

Scanner *newScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->ptr = sc->buf;
    return sc;
}

void freeScanner(Scanner *sc) {
    free(sc);
}

char *nextStr(Scanner *sc) {
    char *res = sc->ptr;
    while (*sc->ptr!= '\0' && *sc->ptr!='') {
        sc->ptr++;
    }
    *sc->ptr = '\0';
    sc->ptr++;
    return res;
}

int nextInt(Scanner *sc) {
    int res = 0;
    while (*sc->ptr!= '\0' && *sc->ptr!='') {
        res = res * 10 + *sc->ptr - '0';
        sc->ptr++;
    }
    while (*sc->ptr!= '\0' && *sc->ptr!='') {
        sc->ptr++;
    }
    return res;
}

float nextFloat(Scanner *sc) {
    float res = 0;
    int i = 0;
    while (*sc->ptr!= '\0' && *sc->ptr!='') {
        res = res * 10 + *sc->ptr - '0';
        sc->ptr++;
        i++;
    }
    if (*sc->ptr == '.') {
        sc->ptr++;
        int d = 1;
        while (*sc->ptr!= '\0' && *sc->ptr!='') {
            res = res + (*sc->ptr - '0') * (1.0 / d);
            d *= 10;
            sc->ptr++;
        }
    }
    while (*sc->ptr!= '\0' && *sc->ptr!='') {
        sc->ptr++;
    }
    return res;
}

char *nextIntSlice(Scanner *sc, int n) {
    char *res = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(sc);
    }
    return res;
}

char *nextFloatSlice(Scanner *sc, int n) {
    char *res = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++) {
        res[i] = nextFloat(sc);
    }
    return res;
}

int run(FILE *input, FILE *output) {
    Scanner *sc = newScanner();
    int N = nextInt(sc);
    char *S = nextStr(sc);

    if (N == 0) {
    }

    if (N < 4) {
        fprintf(output, "%d\n", 0);
        return 0;
    }

    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            nr++;
        }
        if (S[i] == 'B') {
            nb++;
        }
        if (S[i] == 'G') {
            ng++;
        }
    }

    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        if (k >= N) {
            break;
        }
        for (; k < N; i++, j++, k++) {
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++;
            }
        }
    }

    int tot = nr * nb * ng;

    fprintf(output, "%d\n", tot - same);

    freeScanner(sc);
    return 0;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    run(input, output);
    fclose(input);
    fclose(output);
    return 0;
}

