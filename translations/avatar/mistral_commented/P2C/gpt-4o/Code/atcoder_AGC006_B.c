#include <stdio.h>
#include <stdlib.h>

void sub(int *y, int size, int debug) {
    if (debug) {
        for (int i = 0; i < size; i++) {
            printf("D %d ", y[i]);
        }
        printf("\n");
    }

    while (size > 1) {
        int newSize = size - 2;
        int *newY = (int *)malloc(newSize * sizeof(int));
        for (int i = 0; i < newSize; i++) {
            int a[3] = {y[i], y[i + 1], y[i + 2]};
            // Sort the array a to find the middle element
            for (int j = 0; j < 3; j++) {
                for (int k = j + 1; k < 3; k++) {
                    if (a[j] > a[k]) {
                        int temp = a[j];
                        a[j] = a[k];
                        a[k] = temp;
                    }
                }
            }
            newY[i] = a[1]; // Middle element
        }
        free(y);
        y = newY;
        size = newSize;

        if (debug) {
            for (int i = 0; i < size; i++) {
                printf("D %d ", y[i]);
            }
            printf("\n");
        }
    }
}

int calc(int x) {
    int *y = (int *)malloc(sizeof(int) * x);
    for (int i = 0; i < x; i++) {
        y[i] = i + 1; // Initialize y with values from 1 to x
    }

    sub(y, x, 0);
    int result = y[0];
    free(y);

    if (result == 2) {
        sub(y, x, 1);
        printf("= %d\n", x);
    }

    return result;
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    if (X == 1 || X == N * 2 - 1) {
        printf("No\n");
    } else {
        printf("Yes\n");

        if (X == N * 2 - 2) {
            for (int i = N - 1; i <= X + 1; i++) {
                printf("%d\n", i);
            }
            for (int i = 1; i < N - 1; i++) {
                printf("%d\n", i);
            }
        } else {
            for (int i = 1; i < X - 1; i++) {
                printf("%d\n", i);
            }
            for (int i = X + 3; i <= N * 2; i++) {
                printf("%d\n", i);
            }
            // Create the list xs
            printf("%d\n", X + 2);
            printf("%d\n", X - 1);
            printf("%d\n", X);
            printf("%d\n", X + 1);
        }
    }

    return 0;
}
// <END-OF-CODE>
