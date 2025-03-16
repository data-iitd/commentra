#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_N (2000001)
#define MAX_Ai (10001)
#define STR_SIZE (10000010)

int getNum();
void putNum(int n);
void CountingSort(int A[], int B[], int k, int len);

int A[MAX_N];
int B[MAX_N];
char str[STR_SIZE];
char *p = str;

int main() {
    int n;

    std::cin.read(str, STR_SIZE);

    n = getNum();
    for (int i = 1; i <= n; ++i) {
        A[i] = getNum();
    }

    CountingSort(A, B, MAX_Ai, n);

    p = str;
    --n;
    for (int i = 1; i <= n; ++i) {
        putNum(B[i]);
        *p++ = ' ';
    }
    putNum(B[n + 1]);
    *p++ = '\0';

    std::cout.write(str, p - str);

    return 0;
}

int getNum() {
    int n = 0;
    while (*p >= '0' && *p <= '9') {
        n = n * 10 + (*p - '0');
        ++p;
    }
    ++p;
    return n;
}

void putNum(int n) {
    int d;
    if (n < 10) {
        *p++ = '0' + n;
        return;
    }
    d = n / 10;
    if (d) putNum(d);
    *p++ = '0' + (n - (d * 10));
}

void CountingSort(int A[], int B[], int k, int len) {
    int C[MAX_Ai] = { 0 };
    for (int j = 1; j <= len; ++j) {
        ++C[A[j]];
    }
    for (int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    for (int j = len; j > 0; --j) {
        B[C[A[j]]] = A[j];
        --C[A[j]];
    }
}
