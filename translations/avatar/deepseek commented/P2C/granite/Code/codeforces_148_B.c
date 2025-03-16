

#include <stdio.h>

int main() {
    int princess, dragon, t, f, c, result, position;

    // Input the number of princess's power, dragon's power, initial time, time increment, and target power level
    scanf("%d %d %d %d %d", &princess, &dragon, &t, &f, &c);

    // Check if the dragon's power is less than or equal to the princess's power
    if (dragon <= princess) {
        printf("0\n");  // If dragon is not stronger, no attacks needed
        return 0;       // Exit the program
    }

    result = 0;         // Initialize the result counter
    position = t * princess;  // Calculate the initial position based on time and princess's power
    position += princess * position / (dragon - princess);  // Adjust the position based on the given formula

    // Enter a while loop that continues until the position is greater than or equal to the target power level
    while (position < c) {
        result += 1;      // Increment the result counter
        position += princess * position / dragon;  // Update the position based on the dragon's power
        position += princess * f;  // Add the time increment to the position
        position += princess * position / (dragon - princess);  // Adjust the position based on the given formula
    }

    printf("%d\n", result);  // Print the number of attacks needed

    return 0;
}
