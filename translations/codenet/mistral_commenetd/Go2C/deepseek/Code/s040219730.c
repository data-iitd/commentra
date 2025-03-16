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

typedef struct {
    int idx, l, r;
} Query;

int n, q;
int C[500000 + 50];
Query Q[500000 + 50];

int P[500000 + 50];
int Answers[500000 + 50];

int ReadInt() {
    int num;
    scanf("%d", &num);
    return num;
}

void ReadInt2() {
    scanf("%d %d", &n, &q);
}

int* ReadIntSlice(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]);
    }
    return slice;
}

void PrintInt(int num) {
    printf("%d\n", num);
}

void PrintIntsLine(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        int num = va_arg(args, int);
        printf("%d ", num);
    }
    printf("\n");
    va_end(args);
}

void PrintStr(const char* str) {
    printf("%s\n", str);
}

void PrintFenwickTree(FenwickTree* ft) {
    for (int i = 1; i <= ft->n; i++) {
        printf("%d ", ft->dat[i]);
    }
    printf("\n");
}

typedef struct {
    int* dat;
    int n;
    int minPow2;
} FenwickTree;

FenwickTree* NewFenwickTree(int n) {
    FenwickTree* ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->dat = (int*)calloc(n + 1, sizeof(int));
    ft->n = n;
    ft->minPow2 = 1;
    while ((ft->minPow2 << 1) <= n) {
        ft->minPow2 <<= 1;
    }
    return ft;
}

int Sum(FenwickTree* ft, int i) {
    int s = 0;
    while (i > 0) {
        s += ft->dat[i];
        i -= i & (-i);
    }
    return s;
}

void Add(FenwickTree* ft, int i, int x) {
    while (i <= ft->n) {
        ft->dat[i] += x;
        i += i & (-i);
    }
}

int LowerBound(FenwickTree* ft, int w) {
    if (w <= 0) {
        return 0;
    }
    int x = 0;
    for (int k = ft->minPow2; k > 0; k /= 2) {
        if (x + k <= ft->n && ft->dat[x + k] < w) {
            w -= ft->dat[x + k];
            x += k;
        }
    }
    return x + 1;
}

int main() {
    ReadInt2();
    C = ReadIntSlice(n);
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Query query = {i, l, r};
        Q[i] = query;
    }
    qsort(Q, q, sizeof(Query), (int(*)(const void*, const void*))