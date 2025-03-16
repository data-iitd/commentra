#include <stdio.h>

int main() {
    double VP, VD, T, F, C; // Declare variables for VP, VD, T, F, and C
    scanf("%lf", &VP); // Read VP
    scanf("%lf", &VD); // Read VD
    scanf("%lf", &T); // Read T
    scanf("%lf", &F); // Read F
    scanf("%lf", &C); // Read C

    if (VD <= VP) { // Check if VD is less than or equal to VP
        printf("0\n"); // If it is, then the answer is 0
        return 0; // Exit the program
    }

    int answer = 0; // Initialize answer
    double start = T; // Initialize start with T

    while (1) { // Enter a while loop that runs indefinitely
        double x = start * VP / (VD - VP); // Calculate the time it takes to fill a volume VP

        if ((start + x) * VP >= C) { // Check if the total volume filled is greater than or equal to C
            break; // If it is, then we break out of the loop
        }

        start += 2 * x + F; // Update the value of start
        answer++; // Increment the value of answer
    }

    printf("%d\n", answer); // Print the value of answer
    return 0; // Exit the program
}

// <END-OF-CODE>
