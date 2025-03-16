#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)math.MaxInt64
#define INF_BIT60 1LL << 60
#define INF_INT32 (int32_t)math.MaxInt32
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

char* ReadString();
int ReadInt();
int ReadInt2();
int ReadInt3();
int ReadInt4();
int64_t ReadInt64();
int64_t ReadInt64_2();
int64_t ReadInt64_3();
int64_t ReadInt64_4();
int64_t readInt64();
int* ReadIntSlice(int n);
int64_t* ReadInt64Slice(int n);
double ReadFloat64();
double* ReadFloat64Slice(int n);
char* ReadRuneSlice();

char* ZeroPaddingRuneSlice(int n, int digitsNum);
char* PrintIntsLine(int* A, int n);
char* PrintInts64Line(int64_t* A, int n);
void PrintfDebug(const char* format, ...);
void PrintfBufStdout(const char* format, ...);

void init();

char S[8001];
int x, y;

bool dpx[8000][20000] = {false}, dpy[8000][20000] = {false};

void main() {
    strcpy(S, ReadString());
    x = ReadInt();
    y = ReadInt();

    int F[8000] = {0};
    int cur = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[i] = cur;
            cur = 0;
        }
    }
    F[strlen(S)] = cur;
    PrintfDebug("%s\n", F);

    int evens[8000] = {0}, odds[8000] = {0};
    int even_idx = 0, odd_idx = 0;
    for (int i = 0; i <= strlen(S); i++) {
        if (i % 2 == 0) {
            evens[even_idx++] = F[i];
        } else {
            odds[odd_idx++] = F[i];
        }
    }

    dpx[0][10000] = true;
    dpy[0][10000] = true;
    for (int i = 0; i < even_idx; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i+1][j+val] = dpx[i+1][j+val] || dpx[i][j];
            }
            if (j - val >= 2000) {
                dpx[i+1][j-val] = dpx[i+1][j-val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < odd_idx; i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i+1][j+val] = dpy[i+1][j+val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i+1][j-val] = dpy[i+1][j-val] || dpy[i][j];
            }
        }
    }

    if (dpx[even_idx][x+10000] && dpy[odd_idx][y+10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

char* ReadString() {
    static char buf[1024];
    scanf("%s", buf);
    return buf;
}

int ReadInt() {
    return (int)readInt64();
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

int64_t ReadInt64() {
    return readInt64();
}

int64_t ReadInt64_2() {
    int64_t a, b;
    scanf("%lld %lld", &a, &b);
    return a, b;
}

int64_t ReadInt64_3() {
    int64_t a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    return a, b, c;
}

int64_t ReadInt64_4() {
    int64_t a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    return a, b, c, d;
}

int64_t readInt64() {
    int64_t i;
    scanf("%lld", &i);
    return i;
}

int* ReadIntSlice(int n) {
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = ReadInt();
    }
    return a;
}

int64_t* ReadInt64Slice(int n) {
    int64_t* a = (int64_t*)malloc(n * sizeof(int64_t));
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
    static char buf[1024];
    scanf("%s", buf);
    return buf;
}

char* ZeroPaddingRuneSlice(int n, int digitsNum) {
    char* sn = (char*)malloc(64 * sizeof(char));
    sprintf(sn, "%b", n);

    int residualLength = digitsNum - strlen(sn);
    if (residualLength <= 0) {
        return sn;
    }

    char* zeros = (char*)malloc(residualLength * sizeof(char));
    for (int i = 0; i < residualLength; i++) {
        zeros[i] = '0';
    }

    char* res = (char*)malloc((residualLength + strlen(sn)) * sizeof(char));
    strcpy(res, zeros);
    strcat(res, sn);

    free(zeros);
    return res;
}

char* PrintIntsLine(int* A, int n) {
    static char buf[1024];
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += sprintf(buf + p, "%d", A[i]);
        if (i != n - 1) {
            p += sprintf(buf + p, " ");
        }
    }
    return buf;
}

char* PrintInts64Line(int64_t* A, int n) {
    static char buf[1024];
    int p = 0;
    for (int i = 0; i < n; i++) {
        p += sprintf(buf + p, "%lld", A[i]);
        if (i != n - 1) {
            p += sprintf(buf + p, " ");
        }
    }
    return buf;
}

void PrintfDebug(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void PrintfBufStdout(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

