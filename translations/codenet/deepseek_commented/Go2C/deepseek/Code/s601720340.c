#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_N 200000
#define MOD 1000000007

int p[MAX_N];
int N;

int find(int n) {
    for (int i = 0; i < N; i++) {
        if (n == p[i]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int X;
    scanf("%d", &X);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i <= 100; i++) {
        if (find(X - i) == 1) {
            printf("%d\n", X - i);
            exit(0);
        }
        if (find(X + i) == 1) {
            printf("%d\n", X + i);
            exit(0);
        }
    }
}

int main() {
    solve();
    return 0;
}

