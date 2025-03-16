#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define a pair type alias for convenience
typedef struct {
    int first;
    int second;
} P;

// Initialize some variables
bool d[10] = {0}; // A boolean array to keep track of digits that have been seen
int n, k; // Input variables for the number and the number of digits to check
bool hantei = true; // A flag to indicate if the current number is a valid answer

int main() {
    // Read input
    scanf("%d %d", &n, &k);

    // Check each digit in the input number 'k' times
    for (int i = 0; i < k; ++i) {
        int a; // A variable to store the digit to check
        scanf("%d", &a); // Read the digit from the input
        d[a] = 1; // Mark the digit as seen
    }

    // Keep generating numbers until a valid one is found
    while (1) {
        int x = n; // Initialize a variable 'x' to store the current number being checked

        // Initialize a flag 'hantei' to indicate if the current number is valid
        hantei = true;

        // Check each digit in the number 'x'
        while (x) {
            // If the current digit has already been seen, then the number is not valid
            if (d[x % 10]) {
                hantei = false;
                break;
            }
            x /= 10; // Move to the next digit
        }

        // If the current number is valid, print it and exit the loop
        if (hantei) {
            printf("%d\n", n);
            break;
        }

        // If the current number is not valid, increment 'n' and continue checking
        n++;
    }

    return 0;
}
