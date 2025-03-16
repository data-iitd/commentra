#include <stdio.h>

int main() {
    int x, y, a, b;
    // Get user input as a string and convert it to integers
    scanf("%d %d %d %d", &x, &y, &a, &b);
    
    // Initialize a counter for the number of games
    int count = 0;
    
    // Iterate through a range of numbers from a to x
    for (int i = a; i <= x; i++) {
        // If i is less than or equal to b, skip to the next iteration
        if (i <= b) {
            continue;
        }
        // Iterate through a range of numbers from b to y
        for (int j = b; j <= y; j++) {
            // If i is greater than j, increment the count
            if (i > j) {
                count++;
            }
        }
    }

    // Print the length of the games list
    printf("%d\n", count);
    
    // Iterate through the games list and print each tuple
    for (int i = a; i <= x; i++) {
        if (i <= b) {
            continue;
        }
        for (int j = b; j <= y; j++) {
            if (i > j) {
                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
