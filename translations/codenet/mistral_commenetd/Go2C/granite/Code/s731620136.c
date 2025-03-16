
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

int nextInt(Scanner *sc) {
    int n;
    int sign = 1;
    while (*sc->ptr =='' || *sc->ptr == '\n') sc->ptr++;
    if (*sc->ptr == '-') {
        sign = -1;
        sc->ptr++;
    }
    n = 0;
    while (*sc->ptr >= '0' && *sc->ptr <= '9') {
        n = n * 10 + *sc->ptr - '0';
        sc->ptr++;
    }
    return n * sign;
}

char nextChar(Scanner *sc) {
    while (*sc->ptr =='' || *sc->ptr == '\n') sc->ptr++;
    char c = *sc->ptr;
    sc->ptr++;
    return c;
}

void skip(Scanner *sc, char c) {
    while (*sc->ptr!= '\0') {
        if (*sc->ptr == c) {
            sc->ptr++;
            break;
        }
        sc->ptr++;
    }
}

int run(FILE *input, FILE *output) {
    Scanner *sc = newScanner();
    int N = nextInt(sc);
    if (N == 0) {
        fprintf(output, "0\n");
        return 0;
    }
    if (N < 4) {
        fprintf(output, "0\n");
        return 0;
    }
    char S[N];
    fgets(S, N, input);
    int nr = 0, nb = 0, ng = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') nr++;
        if (S[i] == 'B') nb++;
        if (S[i] == 'G') ng++;
    }
    int same = 0;
    for (int a = 1; a < N; a++) {
        int i = 0, j = a, k = 2 * a;
        while (k < N) {
            if (S[i]!= S[j] && S[i]!= S[k] && S[j]!= S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }
    int tot = nr * nb * ng;
    fprintf(output, "%d\n", tot - same);
    return 0;
}

int main() {
    return run(stdin, stdout);
}
// END-OF-CODE