#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10240

typedef struct {
    char line[MAX_LINE_LENGTH];
    size_t pos;
} Scanner;

void initScanner(Scanner *sc) {
    fgets(sc->line, MAX_LINE_LENGTH, stdin);
    sc->pos = 0;
}

char nextChar(Scanner *sc) {
    return sc->line[sc->pos++];
}

int nextInt(Scanner *sc) {
    char buffer[12];
    size_t i = 0;
    char c;
    while ((c = nextChar(sc)) != ' ' && c != '\n') {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return atoi(buffer);
}

float nextFloat(Scanner *sc) {
    char buffer[32];
    size_t i = 0;
    char c;
    while ((c = nextChar(sc)) != ' ' && c != '\n') {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return atof(buffer);
}

char* nextStr(Scanner *sc) {
    char *result = (char*)malloc(MAX_LINE_LENGTH);
    size_t i = 0;
    char c;
    while ((c = nextChar(sc)) != ' ' && c != '\n') {
        result[i++] = c;
    }
    result[i] = '\0';
    return result;
}

char* nextRuneSlice(Scanner *sc) {
    return nextStr(sc);
}

int* nextIntSlice(int n, Scanner *sc) {
    int *result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = nextInt(sc);
    }
    return result;
}

float* nextFloatSlice(int n, Scanner *sc) {
    float *result = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        result[i] = nextFloat(sc);
    }
    return result;
}

int run(FILE *input, FILE *output) {
    Scanner sc;
    initScanner(&sc);
    int N = nextInt(&sc);
    char *S = nextStr(&sc);

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
        int i = 0;
        int j = a;
        int k = 2 * a;
        if (k >= N) {
            break;
        }
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

    free(S);
    return 0;
}

int main() {
    run(stdin, stdout);
    return 0;
}
