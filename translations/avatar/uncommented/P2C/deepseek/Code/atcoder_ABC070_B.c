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
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (A[i] > A[j]) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
        printf("%d\n", A[2] - A[1]);
    }
    return 0;
}
