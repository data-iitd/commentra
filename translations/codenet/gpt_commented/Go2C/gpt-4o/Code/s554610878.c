#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Constants for buffer sizes
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000

// Modulus value for calculations
const int MOD = 1000000007;

// Function to read a string from input
void getString(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Function to calculate the number of days until the next Sunday
int daysUntilNextSunday(const char *day) {
    const char *week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int index = -1; // Initialize index to -1 to indicate not found

    // Search for the input day in the week array
    for (int i = 0; i < 7; i++) {
        if (strcmp(day, week[i]) == 0) {
            index = i; // Update index if the day is found
            break;
        }
    }

    // Calculate and return the number of days until the next Sunday
    return (index == -1) ? -1 : (7 - index) % 7; // Handle not found case
}

int main() {
    char inputDay[4]; // Buffer for input day (3 characters + null terminator)

    // Get the input day as a string
    getString(inputDay, sizeof(inputDay));

    // Calculate and print the number of days until the next Sunday
    int result = daysUntilNextSunday(inputDay);
    if (result == -1) {
        printf("Invalid day\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

// <END-OF-CODE>
