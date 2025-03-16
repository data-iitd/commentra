#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MOD = 1000000007;

// Function to read a string from input
void getString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    const char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    char input[10];

    // Read input string
    getString(input, sizeof(input));

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(week[i], input) == 0) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, print error message
    if (index == -1) {
        fprintf(stderr, "Invalid day of the week\n");
        return 1;
    }

    // Calculate the number of days until Sunday and print the result
    int daysUntilSunday = 7 - index;
    printf("%d\n", daysUntilSunday);

    return 0;
}

// <END-OF-CODE>
