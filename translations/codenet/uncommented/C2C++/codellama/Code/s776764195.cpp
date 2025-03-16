#include <iostream>
#include <cstring>
#include <cstdio>
  
using namespace std;
  
int getNum(void);
void putNum(int n);
void CountingSort(int A[], int B[], int k, int len);
  
int A[1000001];
int B[1000001];
char str[10000010];
char *p = str;
  
int main(void) {
    register int i;
    int n;
  
    fread(str, 1, 10000010, stdin);
      
    n = getNum();
    for (i = 1; i <= n; ++i) {
        A[i] = getNum();
    }
      
    CountingSort(A, B, 10001, n);
      
    p = str;
    --n;
    for (i = 1; i <= n; ++i) {
        putNum(B[i]);
        cout << ' ';
    }
    putNum(B[i]);
    cout << endl;
      
    return 0;
}
  
int getNum(void) {
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
        cout << '0' + n;
        return;
    }
    d = n / 10;
    if (d) putNum(d);
    cout << '0' + (n - (d * 10));
}
  
void CountingSort(int A[], int B[], int k, int len) {
    int C[10001] = { 0 };
    int i, j;
    for (j = 1; j <= len; ++j) {
        ++C[A[j]];
    }
    for (i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }
    for (j = len; j > 0; --j) {
        B[C[A[j]]] = A[j];
        --C[A[j]];
    }
}

