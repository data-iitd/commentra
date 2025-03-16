
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

typedef struct Scanner {
    FILE *fp;
    char buf[1024];
    int idx;
} Scanner;

Scanner *newScanner() {
    Scanner *sc = (Scanner *)malloc(sizeof(Scanner));
    sc->fp = stdin;
    sc->idx = 0;
    return sc;
}

char *nextStr(Scanner *sc) {
    char *res = "";
    while (sc->idx < strlen(sc->buf)) {
        if (sc->buf[sc->idx] =='') {
            sc->idx++;
            break;
        }
        res = (char *)realloc(res, sizeof(char) * (strlen(res) + 1));
        res[strlen(res)] = sc->buf[sc->idx];
        sc->idx++;
    }
    return res;
}

int nextInt(Scanner *sc) {
    char *str = nextStr(sc);
    int res = atoi(str);
    free(str);
    return res;
}

float nextFloat(Scanner *sc) {
    char *str = nextStr(sc);
    float res = atof(str);
    free(str);
    return res;
}

int main() {
    Scanner *sc = newScanner();
    int N = nextInt(sc);
    int D = nextInt(sc);
    int A = nextInt(sc);
    int x[N], h[N];
    for (int i = 0; i < N; i++) {
        x[i] = nextInt(sc);
        h[i] = nextInt(sc);
    }
    int ans = 0, total = 0;
    int qx[N], qh[N], qt = 0;
    for (int i = 0; i < N; i++) {
        while (qt > 0 && qx[qt - 1] < x[i]) {
            total -= qh[qt - 1];
            qt--;
        }
        if (total < h[i]) {
            int damage = h[i] - total;
            ans += damage;
            qx[qt] = x[i] + 2 * D;
            qh[qt] = damage;
            qt++;
            total += damage;
        }
    }
    printf("%d\n", ans);
    return 0;
}
