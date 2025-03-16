#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define DEBUG 0

// -----------------------------------------------------------------------------

// IO helper functions

// Returns next token from input.  It must be initialized by SetInput()
// before the first call.
char* nextToken();
char* nextLine();

// Holds a buffer for output.  It must be initialized by SetOutput().
// All IO functions (read*() and [e]print*()) should write to OutputWriter
// instead of this.
char* OutputBuffer;

// Holds an FILE*.  It must be initialized by SetOutput().
FILE* OutputWriter;

// Set IO functions for interactive input/output.
void SetInteractive(FILE* w, FILE* r) {
    SetUnbufferedInput(r);
    OutputBuffer = NULL;
    OutputWriter = w;
}

// Setup OutputBuffer and OutputWriter.
void SetOutput(FILE* w) {
    OutputWriter = w;
}

// Flushes OutputBuffer
void Flush() {
    if (OutputBuffer != NULL) {
        fflush(OutputWriter);
    }
}

// Returns true if c is a white space
bool IsSpace(char c) {
    switch (c) {
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
        case ' ':
            return true;
    }
    return false;
}

bool IsNewLine(char c) {
    switch (c) {
        case '\n':
        case '\r':
            return true;
    }
    return false;
}

// Setup nextToken with input buffer.
void SetInput(FILE* r) {
    char buffer[1024];
    char* b = buffer;

    int i = 0;
    char* rest() {
        while (i < strlen(b) && IsSpace(b[i])) {
            i++;
        }
        if (i == strlen(b)) {
            return NULL;
        }
        int j = i;
        while (i < strlen(b) && !IsSpace(b[i])) {
            i++;
        }
        char* token = (char*)malloc(i - j + 1);
        strncpy(token, b + j, i - j);
        token[i - j] = '\0';
        return token;
    }
    char* initial() {
        fread(buffer, 1, sizeof(buffer), r);
        b = buffer;
        nextToken = rest;
        return rest();
    }
    nextToken = initial;

    char* restLn() {
        while (i < strlen(b) && IsNewLine(b[i])) {
            i++;
        }
        if (i == strlen(b)) {
            return NULL;
        }
        int j = i;
        while (i < strlen(b) && !IsNewLine(b[i])) {
            i++;
        }
        char* line = (char*)malloc(i - j + 1);
        strncpy(line, b + j, i - j);
        line[i - j] = '\0';
        return line;
    }

    char* initialLn() {
        fread(buffer, 1, sizeof(buffer), r);
        b = buffer;
        nextLine = restLn;
        return restLn();
    }
    nextLine = initialLn;
}

// Setup nextToken without input buffer.
void SetUnbufferedInput(FILE* r) {
    char buffer[1024];
    char* b = buffer;

    int i = 0;
    char* nextToken() {
        while (i < strlen(b) && IsSpace(b[i])) {
            i++;
        }
        if (i == strlen(b)) {
            return NULL;
        }
        int j = i;
        while (i < strlen(b) && !IsSpace(b[i])) {
            i++;
        }
        if (i == j) {
            return NULL;
        }
        char* token = (char*)malloc(i - j + 1);
        strncpy(token, b + j, i - j);
        token[i - j] = '\0';
        return token;
    }
}

// -----------------------------------------------------------------------------

// IO functions

// Reads next token and return it as []byte
char* readb() {
    char* b = nextToken();
    if (b == NULL) {
        return NULL;
    }
    return b;
}

// Reads next token and return it as string
char* reads() {
    return readb();
}

// Read next line as []byte.  Trailing '\n' will not be included.
// See also comments on readb()
char* readbln() {
    char* b = nextLine();
    if (b == NULL) {
        return NULL;
    }
    return b;
}

// Read next line as string
char* readsln() {
    return readbln();
}

// Reads next token and return it as int64
long long readll() {
    char* str = reads();
    return atoll(str);
}

// Reads next token and return it as int
int readi() {
    return (int)readll();
}

// Reads next token and return it as float64
double readf() {
    char* str = reads();
    return atof(str);
}

// Write args to OutputWriter with the format f
int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vfprintf(OutputWriter, format, args);
    va_end(args);
    return ret;
}

// Write args to OutputWriter without format
int println(const char* args) {
    return fprintf(OutputWriter, "%s\n", args);
}

// Write args to stderr with the format f
int eprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vfprintf(stderr, format, args);
    va_end(args);
    return ret;
}

// Write args to stderr without format
int eprintln(const char* args) {
    return fprintf(stderr, "%s\n", args);
}

void debugf(const char* format, ...) {
    if (!DEBUG) {
        return;
    }
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void debug(const char* args) {
    if (!DEBUG) {
        return;
    }
    fprintf(stderr, "%s\n", args);
}

// -----------------------------------------------------------------------------

// Utilities

int sumSlice(int* a, int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i];
    }
    return res;
}

long long sumSlicell(long long* a, int size) {
    long long res = 0;
    for (int i = 0; i < size; i++) {
        res += a[i];
    }
    return res;
}

int readInts(int* a, int N) {
    if (N == 0) {
        N = readi();
    }
    for (int i = 0; i < N; i++) {
        a[i] = readi();
    }
    return N;
}

long long readIntsll(long long* a, int N) {
    if (N == 0) {
        N = readi();
    }
    for (int i = 0; i < N; i++) {
        a[i] = readll();
    }
    return N;
}

// -----------------------------------------------------------------------------

// Simple math functions

const long long INF = 1000000007;
const long long INF2 = 1000000009;
const long long INF3 = 998244353;

int min(int a, int b) {
    return a < b ? a : b;
}

long long minll(long long a, long long b) {
    return a < b ? a : b;
}

double minf(double a, double b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long maxll(long long a, long long b) {
    return a > b ? a : b;
}

double maxf(double a, double b) {
    return a > b ? a : b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

long long absll(long long a) {
    return a < 0 ? -a : a;
}

double absf(double a) {
    return a < 0 ? -a : a;
}

// egcd(a, b) returns d, x, y:
//   d is gcd(a,b)
//   x, y are  integers that satisfy ax + by = d
int egcd(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int d = egcd(b, a % b, y, x);
    *y -= a / b * *x;
    return d;
}

long long egcdll(long long a, long long b, long long* x, long long* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long d = egcdll(b, a % b, y, x);
    *y -= a / b * *x;
    return d;
}

int gcd(int a, int b) {
    int d, x, y;
    return egcd(a, b, &x, &y);
}

long long gcdll(long long a, long long b) {
    long long d, x, y;
    return egcdll(a, b, &x, &y);
}

// set up IO functions
void init() {
    // for non-interactive
    SetInput(stdin);
    SetOutput(stdout);

    // Enable below when interactive.  Its ok to leave above intact.
    SetInteractive(stdout, stdin);
}

int main() {
    init();
    int h = readi();
    int w = readi();
    int k = readi();
    int m[h][w];
    for (int i = 0; i < h; i++) {
        char* s = readsln();
        for (int j = 0; j < w; j++) {
            m[i][j] = s[j];
        }
    }

    int answer = solve(h, w, k, m);
    printf("%d\n", answer);
    return 0;
}

const int Black = 35;

int countBlack(int h, int w, int m[h][w]) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
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
            memcpy(tmp, m, sizeof(tmp));
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

