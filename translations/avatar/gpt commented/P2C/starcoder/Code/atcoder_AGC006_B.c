#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    // Read input values N and X from the user
    int N, X;
    scanf("%d %d", &N, &X);
    
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
            int xs[N - 1 + 2];
            for (int i = 0; i < N - 1 + 2; i++) {
                xs[i] = i;
            }
        } else {
            // Create a list ys with specific ranges and then construct xs
            int ys[N - 3 + 4];
            for (int i = 0; i < N - 3 + 4; i++) {
                ys[i] = i;
            }
            int xs[N - 3 + 4];
            for (int i = 0; i < N - 3 + 4; i++) {
                xs[i] = ys[i];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for (int i = N + 1; i < N - 3 + 4; i++) {
                xs[i] = ys[i];
            }
        }
        
        // Print each element in the final list xs
        for (int i = 0; i < N - 3 + 4; i++) {
            printf("%d\n", xs[i]);
        }
    }
    
    // Return success
    return 0;
}

