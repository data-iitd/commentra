#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000001 * 3

// Function to read the next string from input
char* nextStr() {
    static char buffer[MAX_INPUT_SIZE];
    fgets(buffer, sizeof(buffer), stdin);
    return buffer;
}

// Function to read the next integer from input
int nextInt() {
    char* str = nextStr();
    return atoi(str);
}

int main() {
    // Initialize variables for the answer and the previous integer
    int ans = 0;
    int aPrev = 0;

    // Read the number of integers to process
    int n = nextInt();

    // Loop through each integer input
    for (int i = 0; i < n; i++) {
        int a = nextInt(); // Read the next integer

        // Check conditions based on the current and previous integers
        if (a > i || a > aPrev + 1) { // If the current integer is greater than the index or previous integer + 1
            printf("-1\n"); // Print -1 and exit if the condition is met
            return 0;
        } else if (a == aPrev + 1) { // If the current integer is exactly one more than the previous integer
            ans++; // Increment the answer
        } else { // For all other cases
            ans += a; // Add the current integer to the answer
        }
        aPrev = a; // Update the previous integer to the current one
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
