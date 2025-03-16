
#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }
    if (A[1] <= A[2] || A[3] <= A[0]) {
        printf("0\n");
    } else {
        int min = A[0];
        int max = A[0];
        for (int i = 1; i < 4; i++) {
            if (A[i] < min) {
                min = A[i];
            }
            if (A[i] > max) {
                max = A[i];
            }
        }
        printf("%d\n", max - min);
    }
    return 0;
}
