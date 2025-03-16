#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 1LL << 60
#define INF_INT32 1 << 30
#define NIL -1

typedef struct {
    int idx, l, r;
} Query;

typedef struct {
    int *dat;
    int n;
    int minPow2;
} FenwickTree;

FenwickTree* newFenwickTree(int n) {
    FenwickTree *ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->dat = (int*)calloc(n + 1, sizeof(int));
    ft->n = n;
    ft->minPow2 = 1;
    while ((ft->minPow2 << 1) <= n) {
        ft->minPow2 <<= 1;
    }
    return ft;
}

void fenwickTreeAdd(FenwickTree *ft, int i, int x) {
    while (i <= ft->n) {
        ft->dat[i] += x;
        i += i & (-i);
    }
}

int fenwickTreeSum(FenwickTree *ft, int i) {
    int s = 0;
    while (i > 0) {
        s += ft->dat[i];
        i -= i & (-i);
    }
    return s;
}

int fenwickTreeLowerBound(FenwickTree *ft, int w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = ft->minPow2; k > 0; k /= 2) {
        if (x + k <= ft->n && ft->dat[x + k] < w) {
            w -= ft->dat[x + k];
            x += k;
        }
    }
    return x + 1;
}

int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

void readInt2(int *a, int *b) {
    scanf("%d %d", a, b);
}

void readInt3(int *a, int *b, int *c) {
    scanf("%d %d %d", a, b, c);
}

void readInt4(int *a, int *b, int *c, int *d) {
    scanf("%d %d %d %d", a, b, c, d);
}

int* readIntSlice(int n) {
    int *b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    return b;
}

int64_t readInt64() {
    int64_t i;
    scanf("%lld", &i);
    return i;
}

int64_t* readInt64Slice(int n) {
    int64_t *b = (int64_t*)malloc(n * sizeof(int64_t));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    return b;
}

double readFloat64() {
    double f;
    scanf("%lf", &f);
    return f;
}

double* readFloat64Slice(int n) {
    double *b = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    return b;
}

char* readRuneSlice() {
    char *str = (char*)malloc(1024 * sizeof(char));
    scanf("%s", str);
    return str;
}

char* zeroPaddingRuneSlice(int num, int digitsNum) {
    char *sn = (char*)malloc(33 * sizeof(char));
    sprintf(sn, "%b", num);
    int residualLength = digitsNum - strlen(sn);
    if (residualLength <= 0) {
        return sn;
    }
    char *zeros = (char*)malloc(residualLength + 1);
    for (int i = 0; i < residualLength; i++) {
        zeros[i] = '0';
    }
    zeros[residualLength] = '\0';
    char *res = (char*)malloc((residualLength + strlen(sn) + 1) * sizeof(char));
    strcpy(res, zeros);
    strcat(res, sn);
    free(zeros);
    free(sn);
    return res;
}

void printIntsLine(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void printInts64Line(int64_t *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%lld", A[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void printfDebug(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void print