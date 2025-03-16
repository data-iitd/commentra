
#include <stdio.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    // Define a function to perform calculations on the input list
    int calc(int x[]) {
        // Define a helper function to process the list y
        int sub(int y[], int debug) {
            // If debug mode is on, print the current state of y
            if (debug) {
                for (int i = 0; i < N - 1; i++) {
                    printf("D %d ", y[i]);
                }
                printf("\n");
            }
            // Reduce the list y until it has only one element
            while (N - 1 > 1) {
                // Replace y with the second largest element of every three consecutive elements
                for (int i = 0; i < N - 2; i++) {
                    int temp[3];
                    temp[0] = y[i];
                    temp[1] = y[i + 1];
                    temp[2] = y[i + 2];
                    for (int j = 0; j < 3; j++) {
                        for (int k = j + 1; k < 3; k++) {
                            if (temp[j] < temp[k]) {
                                int temp2 = temp[j];
                                temp[j] = temp[k];
                                temp[k] = temp2;
                            }
                        }
                    }
                    y[i] = temp[1];
                }
                // If debug mode is on, print the current state of y
                if (debug) {
                    for (int i = 0; i < N - 2; i++) {
                        printf("D %d ", y[i]);
                    }
                    printf("\n");
                }
            }
            return y[0];
        }

        // Call the helper function to process x
        int y[N - 1];
        for (int i = 0; i < N - 1; i++) {
            y[i] = x[i];
        }
        int result = sub(y, 0);

        // If the final result is 2, perform additional processing
        if (result == 2) {
            sub(x, 1);
            printf("= ");
            for (int i = 0; i < N - 1; i++) {
                printf("%d ", x[i]);
            }
            printf("\n");
        }

        // Return the final processed value
        return result;
    }

    // Check specific conditions based on the value of X
    if (X == 1 || X == N * 2 - 1) {
        // If X is at the boundaries, print "No"
        printf("No\n");
    } else {
        // If X is within the valid range, print "Yes"
        printf("Yes\n");

        // Handle the case where X is N * 2 - 2
        if (X == N * 2 - 2) {
            // Create a list xs with specific ranges
            int xs[N - 1];
            for (int i = 0; i < N - 1; i++) {
                xs[i] = (i + N - 2) % (N - 1) + 1;
            }
            for (int i = 0; i < N - 1; i++) {
                printf("%d ", xs[i]);
            }
            printf("\n");
        } else {
            // Create a list ys with specific ranges and then construct xs
            int ys[N - 1];
            for (int i = 0; i < N - 1; i++) {
                ys[i] = (i + 1) % (N - 1) + 1;
            }
            int xs[N - 1];
            for (int i = 0; i < N - 3; i++) {
                xs[i] = ys[i];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            for (int i = 0; i < N - 3; i++) {
                printf("%d ", xs[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
