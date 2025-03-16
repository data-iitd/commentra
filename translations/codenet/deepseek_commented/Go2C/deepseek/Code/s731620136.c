#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 10240

typedef struct {
    char buffer[MAX_INPUT_SIZE];
    size_t pos;
    size_t size;
} Scanner;

void initScanner(Scanner *s) {
    s->pos = 0;
    s->size = 0;
}

void fillBuffer(Scanner *s) {
    s->size = fread(s->buffer, 1, MAX_INPUT_SIZE, stdin);
    s->pos = 0;
}

char nextChar(Scanner *s) {
    if (s->pos >= s->size) {
        fillBuffer(s);
    }
    return s->buffer[s->pos++];
}

char* nextStr() {
    Scanner s;
    initScanner(&s);
    int c;
    int len = 0;
    char *str = (char*)malloc(1);
    while ((c = nextChar(&s)) != ' ' && c != '\n' && c != EOF) {
        str = (char*)realloc(str, len + 2);
        str[len++] = c;
    }
    str[len] = '\0';
    return str;
}

int nextInt() {
    char *str = nextStr();
    int num = atoi(str);
    free(str);
    return num;
}

double nextFloat() {
    char *str = nextStr();
    double num = atof(str);
    free(str);
    return num;
}

char* nextRuneSlice() {
    Scanner s;
    initScanner(&s);
    int c;
    int len = 0;
    char *str = (char*)malloc(1);
    while ((c = nextChar(&s)) != ' ' && c != '\n' && c != EOF) {
        str = (char*)realloc(str, len + 2);
        str[len++] = c;
    }
    str[len] = '\0';
    return str;
}

int* nextIntSlice(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt();
    }
    return arr;
}

double* nextFloatSlice(int n) {
    double *arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        arr[i] = nextFloat();
    }
    return arr;
}

int run() {
    int N = nextInt();
    char *S = nextStr();

    if (N == 0) {
        return 0;
    }

    if (N < 4) {
        printf("0\n");
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
    printf("%d\n", tot - same);

    return 0;
}

int main() {
    run();
    return 0;
}
