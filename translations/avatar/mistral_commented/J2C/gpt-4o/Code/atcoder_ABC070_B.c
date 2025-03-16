#include <stdio.h>  // For standard input and output
#include <stdlib.h> // For dynamic memory allocation and other utility functions

int main() {
    // Declare variables for input integers
    int a, b, c, d;

    // Read input integers a, b, c, and d
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Check if c is greater than b
    if (c > b) {
        // If yes, print 0 and exit
        printf("0\n");
        return 0;
    }
    // Check if a is greater than d
    else if (a > d) {
        // If yes, print 0 and exit
        printf("0\n");
        return 0;
    }
    // Check if a is less than c
    else if (a < c) {
        // If yes, calculate the difference between the smaller and larger of b and d
        int difference = (b < d ? b : d) - c;
        // Print the difference
        printf("%d\n", difference);
        return 0;
    }
    // If none of the above conditions are true, then a, b, c, and d are in sorted order
    else {
        // Create an array of integers a, b, c, and d
        int arr[4] = {a, b, c, d};

        // Sort the array in ascending order using a simple bubble sort
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // Calculate the difference between the second and third elements of the sorted array
        int difference = arr[2] - arr[1];

        // Print the difference
        printf("%d\n", difference);
    }

    return 0;
}

// <END-OF-CODE>
