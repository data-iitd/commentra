#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

#define DEBUG 0

typedef long long int64;

// IO helper functions
char buffer[1024];
int bufferIndex = 0;

void setInput(FILE *file) {
    fseek(file, 0, SEEK_SET);
    bufferIndex = 0;
}

char getChar() {
    if (bufferIndex >= bufferSize) {
        bufferSize = fread(buffer, 1, sizeof(buffer), file);
        bufferIndex = 0;
    }
    return buffer[bufferIndex++];
}

void setOutput(FILE *file) {
    setbuf(file, NULL);
}

bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

bool isNewLine(char c) {
    return c == '\n' || c == '\r';
}

char nextToken() {
    char c;
    while (isSpace(c = getChar())) {}
    return c;
}

char nextLine() {
    char c;
    while (isNewLine(c = getChar())) {}
    return c;
}

void printChar(char c) {
    fputc(c, stdout);
}

void printString(const char *str) {
    fputs(str, stdout);
}

void printInt(int num) {
    sprintf(buffer, "%d", num);
    fputs(buffer, stdout);
}

void printInt64(int64 num) {
    sprintf(buffer, "%lld", num);
    fputs(buffer, stdout);
}

void printFloat(float num) {
    sprintf(buffer, "%.6f", num);
    fputs(buffer, stdout);
}

void println() {
    fputc('\n', stdout);
}

void eprintString(const char *str) {
    fputs(str, stderr);
}

void eprintInt(int num) {
    sprintf(buffer, "%d", num);
    fputs(buffer, stderr);
}

void eprintInt64(int64 num) {
    sprintf(buffer, "%lld", num);
    fputs(buffer, stderr);
}

void eprintFloat(float num) {
    sprintf(buffer, "%.6f", num);
    fputs(buffer, stderr);
}

void eprintln() {
    fputc('\n', stderr);
}

void debugString(const char *str) {
    if (!DEBUG) return;
    fputs(str, stderr);
}

void debugInt(int num) {
    if (!DEBUG) return;
    sprintf(buffer, "%d", num);
    fputs(buffer, stderr);
}

void debugInt64(int64 num) {
    if (!DEBUG) return;
    sprintf(buffer, "%lld", num);
    fputs(buffer, stderr);
}

void debugFloat(float num) {
    if (!DEBUG) return;
    sprintf(buffer, "%.6f", num);
    fputs(buffer, stderr);
}

void debugln() {
    if (!DEBUG) return;
    fputc('\n', stderr);
}

// Utilities
int sumSlice(int *a, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i];
    }
    return res;
}

int64 sumSlicell(int64 *a, int size) {
    int64 res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i];
    }
    return res;
}

// Simple math functions
int min(int a, int b) {
    return a < b ? a : b;
}

int64 minll(int64 a, int64 b) {
    return a < b ? a : b;
}

float minf(float a, float b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int64 maxll(int64 a, int64 b) {
    return a > b ? a : b;
}

float maxf(float a, float b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int64 absll(int64 a) {
    return a < 0 ? -a : a;
}

float absf(float a) {
    return a < 0 ? -a : a;
}

// Main function
int main() {
    setInput(stdin);
    setOutput(stdout);

    int h, w, a;
    h = nextToken() - '0';
    w = nextToken() - '0';
    a = nextToken() - '0';

    int m[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            m[i][j] = nextToken() - '0';
        }
    }

    int result = solve(h, w, a, m);
    printInt(result);
    println();

    return 0;
}

int countBlack(int h, int w, int m[h][w]) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == 35) {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int a, int m[h][w]) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            int tmp[h][w];
            memcpy(tmp, m, sizeof(m));
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

