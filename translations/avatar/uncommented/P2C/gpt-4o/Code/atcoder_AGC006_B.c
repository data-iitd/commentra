#include <stdio.h>
#include <stdlib.h>

void sub(int *y, int len) {
    while (len > 1) {
        for (int i = 0; i < len - 2; i++) {
            int arr[3] = {y[i], y[i + 1], y[i + 2]};
            // Sort the array to find the middle element
            for (int j = 0; j < 3; j++) {
                for (int k = j + 1; k < 3; k++) {
                    if (arr[j] > arr[k]) {
                        int temp = arr[j];
                        arr[j] = arr[k];
                        arr[k] = temp;
                    }
                }
            }
            y[i] = arr[1]; // The middle element
        }
        len -= 2; // Reduce the length
    }
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
            int ys[2 * N]; // Temporary array to hold values
            int count = 0;

            for (int i = 1; i < X - 1; i++) {
                ys[count++] = i;
            }
            for (int i = X + 3; i < N * 2; i++) {
                ys[count++] = i;
            }

            // Insert the specific values
            ys[count++] = X + 2;
            ys[count++] = X - 1;
            ys[count++] = X;
            ys[count++] = X + 1;

            // Print the first N-3 elements
            for (int i = 0; i < N - 3; i++) {
                printf("%d\n", ys[i]);
            }
            // Print the remaining elements
            for (int i = N - 3; i < count; i++) {
                printf("%d\n", ys[i]);
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
