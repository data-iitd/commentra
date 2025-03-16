#include <stdio.h>
#include <stdlib.h>

// Define a function to perform calculations on the input list
int calc(int x) {
    // Define a helper function to process the list y
    int sub(int y, int debug) {
        // If debug mode is on, print the current state of y
        if (debug) {
            printf("D %d\n", y);
        }
        // Reduce the list y until it has only one element
        while (y > 1) {
            // Replace y with the second largest element of every three consecutive elements
            y = (y > 2) ? (y - 1) : (y + 1);
            // If debug mode is on, print the current state of y
            if (debug) {
                printf("D %d\n", y);
            }
        }
        return y;
    }
    
    // Call the helper function to process x
    int y = sub(x, 0);
    
    // If the final result is 2, perform additional processing
    if (y == 2) {
        sub(x, 1);  // Call sub with debug mode on
        printf("= %d\n", x);  // Print the original list x
    }
    
    // Return the final processed value
    return y;
}

// Check specific conditions based on the value of X
int main() {
    int N, X;
    scanf("%d %d", &N, &X);
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
                xs[i] = N - 1 - i;
            }
            for (int i = 0; i < N - 1; i++) {
                xs[i + N - 1] = i + 1;
            }
        } else {
            // Create a list ys with specific ranges and then construct xs
            int ys[N * 2 - 3];
            for (int i = 0; i < N * 2 - 3; i++) {
                ys[i] = i + 1;
            }
            int xs[N * 2 - 3];
            for (int i = 0; i < N - 3; i++) {
                xs[i] = ys[i];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for (int i = 0; i < N - 3; i++) {
                xs[i + N + 1] = ys[i + N - 3];
            }
        }
        
        // Print each element in the final list xs
        for (int i = 0; i < N * 2 - 1; i++) {
            printf("%d\n", xs[i]);
        }
    }
    return 0;
}

