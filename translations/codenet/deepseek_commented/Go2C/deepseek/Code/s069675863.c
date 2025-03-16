#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 (long long)INT_MAX * INT_MAX
#define INF_BIT60 1LL << 60
#define INF_INT32 INT_MAX
#define INF_BIT30 1 << 30
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

char* ReadString();
long long ReadInt64();
int ReadInt();
int ReadInt2();
int ReadInt3();
int ReadInt4();
long long ReadInt64_2();
long long ReadInt64_3();
long long ReadInt64_4();
int ReadIntSlice(int n);
long long ReadInt64Slice(int n);
double ReadFloat64();
double ReadFloat64Slice(int n);
char* ReadRuneSlice();
char* ZeroPaddingRuneSlice(int n, int digitsNum);
int Strtoi(char* s);
char* PrintIntsLine(int* A, int n);
char* PrintInts64Line(long long* A, int n);
void PrintfDebug(char* format, ...);
void PrintfBufStdout(char* format, ...);

char* ReadString() {
    // Implement this function to read a string from stdin
    // For simplicity, let's assume we are reading a fixed-size buffer
    static char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}

long long ReadInt64() {
    char* str = ReadString();
    return strtoll(str, NULL, 10);
}

int ReadInt() {
    return (int)ReadInt64();
}

int ReadInt2() {
    return (int)ReadInt64_2();
}

int ReadInt3() {
    return (int)ReadInt64_3();
}

int ReadInt4() {
    return (int)ReadInt64_4();
}

long long ReadInt64_2() {
    char* str = ReadString();
    return strtoll(str, NULL, 10);
}

long long ReadInt64_3() {
    char* str = ReadString();
    return strtoll(str, NULL, 10);
}

long long ReadInt64_4() {
    char* str = ReadString();
    return strtoll(str, NULL, 10);
}

int ReadIntSlice(int n) {
    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        A[i] = ReadInt();
    }
    return A;
}

long long ReadInt64Slice(int n) {
    long long* A = (long long*)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        A[i] = ReadInt64();
    }
    return A;
}

double ReadFloat64() {
    char* str = ReadString();
    return strtod(str, NULL);
}

double ReadFloat64Slice(int n) {
    double* A = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        A[i] = ReadFloat64();
    }
    return A;
}

char* ReadRuneSlice() {
    char* str = ReadString();
    return strdup(str);
}

char* ZeroPaddingRuneSlice(int n, int digitsNum) {
    char* sn = (char*)malloc(32 * sizeof(char));
    sprintf(sn, "%lld", n);

    int residualLength = digitsNum - strlen(sn);
    if (residualLength <= 0) {
        return sn;
    }

    char* zeros = (char*)malloc(residualLength * sizeof(char));
    for (int i = 0; i < residualLength; i++) {
        zeros[i] = '0';
    }

    char* res = (char*)malloc((residualLength + strlen(sn) + 1) * sizeof(char));
    sprintf(res, "%s%s", zeros, sn);

    free(zeros);
    free(sn);
    return res;
}

int Strtoi(char* s) {
    char* endptr;
    int value = strtol(s, &endptr, 10);
    if (endptr == s) {
        fprintf(stderr, "No digits were found\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

char* PrintIntsLine(int* A, int n) {
    char* res = (char*)malloc(1024 * sizeof(char));
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += sprintf(res + k, "%d", A[i]);
        if (i != n - 1) {
            k += sprintf(res + k, " ");
        }
    }
    return res;
}

char* PrintInts64Line(long long* A, int n) {
    char* res = (char*)malloc(1024 * sizeof(char));
    int k = 0;
    for (int i = 0; i < n; i++) {
        k += sprintf(res + k, "%lld", A[i]);
        if (i != n - 1) {
            k += sprintf(res + k, " ");
        }
    }
    return res;
}

void PrintfDebug(char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void PrintfBufStdout(char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

