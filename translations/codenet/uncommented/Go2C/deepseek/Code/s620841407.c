#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 LONG_MAX
#define INF_BIT60 1LL << 60
#define INF_INT32 INT_MAX
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef long long ll;

char* ReadString();
int ReadInt();
int ReadInt2();
int ReadInt3();
int ReadInt4();
ll ReadInt64();
ll ReadInt64_2();
ll ReadInt64_3();
ll ReadInt64_4();
int* ReadIntSlice(int n);
ll* ReadInt64Slice(int n);
double ReadFloat64();
double* ReadFloat64Slice(int n);
char* ReadRuneSlice();

char* ReadString() {
    static char buf[1024];
    scanf("%s", buf);
    return buf;
}

int ReadInt() {
    return (int)ReadInt64();
}

int ReadInt2() {
    int a, b;
    scanf("%d %d", &a, &b);
    return a, b;
}

int ReadInt3() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    return a, b, c;
}

int ReadInt4() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    return a, b, c, d;
}

ll ReadInt64() {
    ll i;
    scanf("%lld", &i);
    return i;
}

ll ReadInt64_2() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    return a, b;
}

ll ReadInt64_3() {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    return a, b, c;
}

ll ReadInt64_4() {
    ll a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    return a, b, c, d;
}

int* ReadIntSlice(int n) {
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = ReadInt();
    }
    return a;
}

ll* ReadInt64Slice(int n) {
    ll* a = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        a[i] = ReadInt64();
    }
    return a;
}

double ReadFloat64() {
    return (double)readFloat64();
}

double readFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

double* ReadFloat64Slice(int n) {
    double* a = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        a[i] = ReadFloat64();
    }
    return a;
}

char* ReadRuneSlice() {
    return ReadString();
}

char* ZeroPaddingRuneSlice(int n, int digitsNum) {
    char* sn = (char*)malloc(33 * sizeof(char));
    sprintf(sn, "%lld", n);

    int residualLength = digitsNum - strlen(sn);
    if (residualLength <= 0) {
        return sn;
    }

    char* zeros = (char*)malloc(residualLength + 1);
    for (int i = 0; i < residualLength; i++) {
        zeros[i] = '0';
    }
    zeros[residualLength] = '\0';

    char* res = (char*)malloc(digitsNum + 1);
    strcpy(res, zeros);
    strcat(res, sn);

    free(sn);
    free(zeros);
    return res;
}

int Strtoi(char* s) {
    int i;
    if (sscanf(s, "%d", &i) != 1) {
        fprintf(stderr, "Error: Strtoi only accepts integer string\n");
        exit(EXIT_FAILURE);
    }
    return i;
}

char* PrintIntsLine(int* A, int n) {
    char* res = (char*)malloc(n * 5 + 1);
    int k = 0;

    for (int i = 0; i < n; i++) {
        char* str = (char*)malloc(6 * sizeof(char));
        sprintf(str, "%d", A[i]);
        strcpy(res + k, str);
        k += strlen(str);
        if (i != n - 1) {
            res[k++] = ' ';
        }
        free(str);
    }
    res[k] = '\0';
    return res;
}

char* PrintInts64Line(ll* A, int n) {
    char* res = (char*)malloc(n * 12 + 1);
    int k = 0;

    for (int i = 0; i < n; i++) {
        char* str = (char*)malloc(21 * sizeof(char));
        sprintf(str, "%lld", A[i]);
        strcpy(res + k, str);
        k += strlen(str);
        if (i != n - 1) {
            res[k++] = ' ';
        }
        free(str);
    }
    res[k] = '\0';
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
    vprintf(format, args);
    va_end(args);
}

