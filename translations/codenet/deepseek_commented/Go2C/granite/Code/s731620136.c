
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
    char *end;
    int res = strtol(sc->ptr, &end, 10);
    sc->ptr = end;
    return res;
}

float nextFloat(Scanner *sc) {
    char *end;
    float res = strtof(sc->ptr, &end);
    sc->ptr = end;
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
        } else if (S[i] == 'B') {
            nb++;
        } else if (S[i] == 'G') {
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

    return 0;
}

int main() {
    return run(stdin, stdout);
}
