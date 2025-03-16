#include <stdio.h>

int main() {
    double VP, VD, T, F, C; // Declare variables for speeds, time, refuel time, and distance
    scanf("%lf", &VP); // Read the initial speed of the police car (VP)
    scanf("%lf", &VD); // Read the initial speed of the thief car (VD)
    scanf("%lf", &T);  // Read the initial head start time (T)
    scanf("%lf", &F);  // Read the time it takes for the police car to refuel (F)
    scanf("%lf", &C);  // Read the distance to catch the thief (C)

    if (VD <= VP) {
        printf("0\n"); // If the thief's speed is not greater than the police's speed, print 0 and exit
        return 0;
    }

    int answer = 0; // Initialize the answer variable to 0
    double start = T; // Initialize the start variable to the initial head start time (T)

    while (1) {
        double x = start * VP / (VD - VP); // Calculate the distance covered by the police car in one unit of time

        if ((start + x) * VP >= C) {
            break; // If the total distance covered by the police car is greater than or equal to C, break the loop
        }

        start += 2 * x + F; // Update the start variable by adding the distance covered and the refueling time
        answer++; // Increment the answer variable by 1
    }

    printf("%d\n", answer); // Print the final value of answer
    return 0;
}

// <END-OF-CODE>
