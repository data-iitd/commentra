#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    char **tokens;
    int nextToken;
    int tokenCount;
} Io;

Io* createIo() {
    Io *io = (Io*)malloc(sizeof(Io));
    io->tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    io->nextToken = 0;
    io->tokenCount = 0;
    return io;
}

void freeIo(Io *io) {
    for (int i = 0; i < io->tokenCount; i++) {
        free(io->tokens[i]);
    }
    free(io->tokens);
    free(io);
}

void addToken(Io *io, char *token) {
    io->tokens[io->tokenCount++] = token;
}

void readLine(Io *io) {
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, MAX_LINE_LENGTH, stdin);
    char *token = strtok(buffer, " \n");
    while (token != NULL) {
        addToken(io, token);
        token = strtok(NULL, " \n");
    }
}

char* next(Io *io) {
    if (io->nextToken >= io->tokenCount) {
        readLine(io);
    }
    return io->tokens[io->nextToken++];
}

int nextInt(Io *io) {
    char *str = next(io);
    return atoi(str);
}

double nextDouble(Io *io) {
    char *str = next(io);
    return atof(str);
}

void printLn(char *str) {
    printf("%s\n", str);
}

void printIntLn(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printStringLn(char **a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int* cumSum(int *nums, int n) {
    int *sums = (int*)malloc((n + 1) * sizeof(int));
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int main() {
    Io *io = createIo();

    int n = nextInt(io);
    int aa[n];
    for (int i = 0; i < n; i++) {
        aa[i] = nextInt(io);
    }

    int *cumsum = cumSum(aa, n);

    int ans = 2020202020;
    for (int i = 1; i < n - 1; i++) {
        int left = cumsum[i];
        int right = cumsum[n] - cumsum[i];
        int diff = abs(left - right);
        if (diff < ans) {
            ans = diff;
        }
    }

    printf("%d\n", ans);

    free(cumsum);
    freeIo(io);
    return 0;
}

