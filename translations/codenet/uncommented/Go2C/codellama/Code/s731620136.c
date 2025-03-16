#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scanner {
    char *str;
    int pos;
} Scanner;

Scanner *NewScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->str = (char *)malloc(10240 * sizeof(char));
    sc->pos = 0;
    return sc;
}

char nextChar(Scanner *sc) {
    if (sc->pos >= strlen(sc->str)) {
        return '\0';
    }
    return sc->str[sc->pos++];
}

int nextInt(Scanner *sc) {
    int res = 0;
    char c = nextChar(sc);
    while (c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = nextChar(sc);
    }
    return res;
}

char *nextStr(Scanner *sc) {
    char *res = (char *)malloc(10240 * sizeof(char));
    int i = 0;
    char c = nextChar(sc);
    while (c != ' ' && c != '\0') {
        res[i++] = c;
        c = nextChar(sc);
    }
    res[i] = '\0';
    return res;
}

int main() {
    Scanner *sc = NewScanner();
    fgets(sc->str, 10240, stdin);
    int N = nextInt(sc);
    char *S = nextStr(sc);

    if (N == 0) {
    }

    if (N < 4) {
        printf("%d\n", 0);
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
    // int etot = 0;
    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = 1 * a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
        while (k < N) {
            // etot++;
            // printf("(%4d) [%2d] (%3d, %3d, %3d)", etot, a, i, j, k);
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
                // printf(" (%4d)", same);
            }
            // printf("\n");
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;

    // int sum = 0;
    // int sum2 = 0;
    // for (int k = 2; k < N; k++) {
    //     for (int j = 1; j < k; j++) {
    //         for (int i = 0; i < j; i++) {
    //             if (j - i == k - j) {
    //                 if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
    //                     sum2++;
    //                 }
    //                 continue;
    //             }

    //             if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
    //                 sum++;
    //             }
    //         }
    //     }
    // }

    // printf("%d %d %d %d\n", tot, same, sum, sum2);
    printf("%d\n", tot - same);

    return 0;
}
