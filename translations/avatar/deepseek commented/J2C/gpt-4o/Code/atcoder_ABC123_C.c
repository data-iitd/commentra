#include <stdio.h>
#include <math.h>

int main() {
    long N;
    scanf("%ld", &N); // Read the value of N

    // Initialize min to a large value and find the minimum of the first five inputs
    long min = LONG_MAX; 
    for (int i = 0; i < 5; i++) {
        long input;
        scanf("%ld", &input);
        if (input < min) {
            min = input; // Update min if the current input is smaller
        }
    }

    // Calculate the result and print it
    long result = (long)ceil((double)N / min) + 4;
    printf("%ld\n", result); // Print the result

    return 0;
}

// <END-OF-CODE>
