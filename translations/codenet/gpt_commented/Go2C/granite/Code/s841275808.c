
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a new scanner to read input from standard input
    FILE *fp = stdin;
    char buf[1024];
    fgets(buf, sizeof(buf), fp);
    int N = atoi(buf);
    int X[N], Y[N];
    for (int i = 0; i < N; i++) {
        fgets(buf, sizeof(buf), fp);
        X[i] = atoi(buf);
        Y[i] = X[i];
    }
    qsort(Y, N, sizeof(int), cmpfunc);
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];
    for (int i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2);
        } else {
            printf("%d\n", m1);
        }
    }
    return 0;
}

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// 