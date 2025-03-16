#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int N, X;
    scanf("%d %d", &N, &X);
    // Read input values N and X from the standard input

    if (X == 1 || X == N * 2 - 1) {
        // Check if X is equal to 1 or N*2-1
        printf("No\n");
        // If it is, print "No"
    } else {
        // Else, X is neither 1 nor N*2-1
        printf("Yes\n");
        // Print "Yes"

        if (X == N * 2 - 2) {
            int xs[N-1+2];
            for (int i = 0; i < N-1+2; i++) {
                xs[i] = i;
            }
        } else {
            int ys[N-3+4];
            for (int i = 0; i < N-3+4; i++) {
                ys[i] = i;
            }
            int xs[N-3+4];
            for (int i = 0; i < N-3+4; i++) {
                xs[i] = ys[i];
            }
            xs[N-3] = X+2;
            xs[N-2] = X-1;
            xs[N-1] = X;
            xs[N] = X+1;
        }
        // Calculate the list xs based on the value of X

        for (int i = 0; i < N-3+4; i++) {
            printf("%d\n", xs[i]);
        }
        // Print each element of the list xs
    }

    return EXIT_SUCCESS;
}
// 