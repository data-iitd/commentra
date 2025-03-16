
#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int gcd = A[0];
    for (int i = 1; i < N; i++) {
        int temp = gcd;
        while (A[i]!= 0) {
            if (temp > A[i]) {
                temp = temp - A[i];
            } else {
                A[i] = A[i] - temp;
            }
        }
        gcd = temp;
    }
    printf("%d\n", gcd);
    return 0;
}

