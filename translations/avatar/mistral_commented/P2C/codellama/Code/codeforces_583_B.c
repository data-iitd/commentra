#include <stdio.h>

// Define the main function
int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Read the array of integers
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize variables
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    // Main loop
    while (counter < n) {
        // Increment turns counter
        counter_turns++;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If current index is valid and its value is less than or equal to current level
            if (a[i] != -1 && a[i] <= counter) {
                // Increment counter and mark the index as visited
                counter++;
                a[i] = -1;
            }
        }

        // Reverse the array
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = temp;
        }
    }

    // Print the result
    printf("%d\n", counter_turns);

    return 0;
}

