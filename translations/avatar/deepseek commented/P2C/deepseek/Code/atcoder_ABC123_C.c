#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }

    int min_A = INT_MAX;
    for (int i = 0; i < 5; i++) {
        if (A[i] < min_A) {
            min_A = A[i];
        }
    }

    int result = (int)ceil((double)N / min_A) + 4;
    printf("%d\n", result);

    return 0;
}
