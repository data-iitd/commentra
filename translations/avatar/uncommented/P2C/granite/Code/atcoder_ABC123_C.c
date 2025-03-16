
#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }
    int min = A[0];
    for (int i = 1; i < 5; i++) {
        if (A[i] < min) {
            min = A[i];
        }
    }
    printf("%d\n", (int)ceil((double)N / min) + 4);
    return 0;
}
// END-OF-CODE