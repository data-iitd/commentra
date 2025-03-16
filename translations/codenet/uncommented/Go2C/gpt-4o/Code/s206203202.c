#include <stdio.h>
#include <stdlib.h>

int Abs(int x) {
    return (x < 0) ? -x : x;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int x = N % K;
    x = min(Abs(x - K), x);
    printf("%d\n", x);

    return 0;
}

// <END-OF-CODE>
