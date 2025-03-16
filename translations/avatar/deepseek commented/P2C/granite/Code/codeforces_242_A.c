

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    // Taking input values for x, y, a, and b
    int **games = (int **)malloc(sizeof(int *) * (x - a + 1));
    // Initializing a 2D array called games with (x - a + 1) rows and 2 columns
    int k = 0;
    // Initializing a variable k to 0
    for (int i = a; i <= x; i++) {
        // Looping from a to x
        if (i <= b) {
            continue;
            // Skipping values of i that are less than or equal to b
        } else {
            for (int j = b; j <= y; j++) {
                // Looping from b to y
                if (i > j) {
                    games[k] = (int *)malloc(sizeof(int) * 2);
                    // Allocating memory for a new row in the games array
                    games[k][0] = i;
                    // Assigning the value of i to the first element of the new row
                    games[k][1] = j;
                    // Assigning the value of j to the second element of the new row
                    k++;
                    // Incrementing the variable k by 1
                }
            }
        }
    }
    printf("%d\n", k);
    // Printing the number of rows in the games array
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", games[i][0], games[i][1]);
        // Printing the values of the first and second elements of each row in the games array
    }
    for (int i = 0; i < k; i++) {
        free(games[i]);
        // Freeing the memory allocated for each row in the games array
    }
    free(games);
    // Freeing the memory allocated for the games array
    return 0;
}
// End of code