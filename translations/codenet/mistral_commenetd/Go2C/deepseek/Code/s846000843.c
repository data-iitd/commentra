#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char tokens[MAX_TOKENS][MAX_LINE_LENGTH];
    int token_count;
} Io;

Io* newIo() {
    Io* io = (Io*)malloc(sizeof(Io));
    io->token_count = 0;
    return io;
}

void flush(Io* io) {
    // No-op in C, as there's no equivalent to Go's bufio.Writer
}

void nextLine(Io* io) {
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, sizeof(buffer), stdin);
    // Split the line into tokens and store them in io->tokens
    char* token = strtok(buffer, " \n");
    while (token != NULL) {
        strcpy(io->tokens[io->token_count++], token);
        token = strtok(NULL, " \n");
    }
}

char* next(Io* io) {
    if (io->token_count == 0) {
        nextLine(io);
    }
    return io->tokens[0];
}

int toInt(Io* io) {
    return atoi(next(io));
}

void printLn(Io* io, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    fprintf(stdout, "\n");
    va_end(args);
}

void printIntLn(Io* io, int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int* cumSum(int* nums, int n) {
    int* sums = (int*)malloc(sizeof(int) * (n + 1));
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    return sums;
}

int main() {
    Io* io = newIo();
    int n = toInt(io);
    int* aa = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        aa[i] = toInt(io);
    }

    int* cumsum = cumSum(aa, n);
    int ans = 2020202020;

    for (int i = 1; i < n - 1; i++) {
        int diff1 = abs(cumsum[n] - cumsum[i]);
        int diff2 = cumsum[i] - cumsum[0];
        ans = min(ans, diff1, diff2);
    }

    printLn(io, "%d", ans);
    free(aa);
    free(cumsum);
    free(io);
    return 0;
}

