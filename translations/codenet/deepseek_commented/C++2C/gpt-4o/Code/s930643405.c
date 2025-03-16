#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int first;
    int second;
} P;

// Define an array to keep track of unavailable digits
bool d[10] = {false};

// Define variables to store the number and the number of unavailable digits
int n, k;

// Define a boolean variable to check if the current number is valid
bool hantei = true;

int main() {
    // Read the initial number and the number of unavailable digits
    scanf("%d %d", &n, &k);

    // Mark the unavailable digits
    for (int i = 0; i < k; ++i) {
        int a;
        scanf("%d", &a);
        d[a] = true;
    }

    // Loop until a valid number is found
    while (1) {
        // Copy the current number to a temporary variable and initialize the check flag
        int x = n;
        hantei = true;

        // Check each digit of the number
        while (x) {
            // If a digit is unavailable, set the check flag to false and break the loop
            if (d[x % 10]) {
                hantei = false;
                break;
            }
            // Move to the next digit
            x /= 10;
        }

        // If the number is valid, print it and break the loop
        if (hantei) {
            printf("%d\n", n);
            break;
        }

        // Increment the number and check again
        n++;
    }

    return 0;
}

// <END-OF-CODE>
