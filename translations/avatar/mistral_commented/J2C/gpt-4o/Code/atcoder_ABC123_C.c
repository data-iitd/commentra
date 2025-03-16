#include <stdio.h>
#include <math.h> // For ceil function

// Function to print a long integer as output
void p(long ans) {
    printf("%ld\n", ans);
}

// Main function where the execution of the program starts
int main() {
    // Reading the first long integer input N
    long N;
    scanf("%ld", &N);

    // Initializing the minimum long integer variable with the first input value
    long min;
    for (int i = 0; i < 5; i++) {
        long current;
        scanf("%ld", &current); // Read the current input value
        if (i == 0) { // If it's the first iteration of the loop
            min = current; // Set the minimum value to the current input value
        } else { // Otherwise
            if (current < min) {
                min = current; // Update the minimum value if the current input is smaller
            }
        }
    }

    // Printing the answer
    p((long)ceil((double)N / min) + 4);

    return 0; // Indicate that the program ended successfully
}

// <END-OF-CODE>
