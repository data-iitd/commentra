#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int result = A[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, A[i]);
    }
    printf("%d\n", result);
    return 0;
}
