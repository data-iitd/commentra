#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    int minA = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < minA) {
            minA = A[i];
        }
    }

    int result = (int)ceil((double)N / minA) + 4;
    printf("%d\n", result);

    return 0;
}
