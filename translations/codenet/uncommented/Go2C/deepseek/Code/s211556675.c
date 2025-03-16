#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I/O
char* readLine() {
    char *line = NULL;
    size_t size = 0;
    if (getline(&line, &size, stdin) == -1) {
        perror("getline");
        exit(EXIT_FAILURE);
    }
    return line;
}

int readInt() {
    char *line = readLine();
    return atoi(line);
}

double readDouble() {
    char *line = readLine();
    return atof(line);
}

// Arithmetic
int max(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

// Sort
typedef struct {
    int id, num;
} Val;

int compare(const void *a, const void *b) {
    return ((Val*)a)->num - ((Val*)b)->num;
}

int main() {
    int A, B, C, K;
    A = readInt();
    B = readInt();
    C = readInt();
    K = readInt();

    int ma = max(A, B, C);
    int rest = 0;
    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    printf("%d\n", ma + rest);
    return 0;
}
