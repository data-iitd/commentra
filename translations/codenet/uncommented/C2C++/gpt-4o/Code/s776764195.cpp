#include <iostream>
#include <vector>
#include <cstdio>

#define PutChar(c) ; *p = (char)(c); ++p;

#define MAX_N (2000001)
#define MAX_Ai (10001)
#define STR_SIZE (10000010)

int getNum();
void putNum(int n);
void CountingSort(std::vector<int>& A, std::vector<int>& B, int k, int len);

char str[STR_SIZE];
char* p = str;

int main() {
    int n;

    std::fread(str, 1, STR_SIZE, stdin);

    n = getNum();
    std::vector<int> A(n + 1);
    std::vector<int> B(n + 1);

    for (int i = 1; i <= n; ++i) {
        A[i] = getNum();
    }

    CountingSort(A, B, MAX_Ai, n);

    p = str;
    --n;
    for (int i = 1; i <= n; ++i) {
        putNum(B[i]);
        PutChar(' ');
    }
    putNum(B[n + 1]);
    PutChar('\0');

    std::puts(str);

    return 0;
}

int getNum() {
    int n = 0;
    while ((*p >= '0') && (*p <= '9')) {
        n = n * 10 + (int)(*p - '0');
        ++p;
    }
    ++p;
    return n;
}

void putNum(int n) {
    int d;
    if (n < 10) {
        PutChar('0' + n);
        return;
    }
    d = n / 10;
    if (d) putNum(d);
    PutChar('0' + (n - (d * 10)));
}

void CountingSort(std::vector<int>& A, std::vector<int>& B, int k, int len) {
    std::vector<int> C(MAX_Ai, 0);
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

// <END-OF-CODE>
