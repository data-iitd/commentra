#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10240

typedef struct {
    char buffer[MAX_INPUT_SIZE];
    size_t pos;
} Scanner;

void initScanner(Scanner *sc) {
    fread(sc->buffer, 1, sizeof(sc->buffer), stdin);
    sc->pos = 0;
}

int nextInt(Scanner *sc) {
    int num = 0;
    int sign = 1;
    while (sc->buffer[sc->pos] < '0' || sc->buffer[sc->pos] > '9') {
        if (sc->buffer[sc->pos] == '-') {
            sign = -1;
        }
        sc->pos++;
    }
    while (sc->buffer[sc->pos] >= '0' && sc->buffer[sc->pos] <= '9') {
        num = num * 10 + (sc->buffer[sc->pos] - '0');
        sc->pos++;
    }
    return num * sign;
}

void run(FILE *input, FILE *output) {
    Scanner sc;
    initScanner(&sc);

    int N = nextInt(&sc);

    if (N == 0) {
        fprintf(output, "0\n");
        return;
    }

    if (N < 4) {
        fprintf(output, "0\n");
        return;
    }

    int nr = 0, nb = 0, ng = 0;
    char S[N + 1];
    for (int i = 0; i < N; i++) {
        S[i] = sc.buffer[sc.pos++];
        if (S[i] == 'R') {
            nr++;
        } else if (S[i] == 'B') {
            nb++;
        } else if (S[i] == 'G') {
            ng++;
        }
    }
    S[N] = '\0';

    int same = 0;

    for (int a = 1; a < N; a++) {
        int i = 0;
        int j = a;
        int k = 2 * a;

        while (k < N) {
            if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k]) {
                same++;
            }
            i++;
            j++;
            k++;
        }
    }

    int tot = nr * nb * ng;

    fprintf(output, "%d\n", tot - same);
}

int main() {
    run(stdin, stdout);
    return 0;
}
