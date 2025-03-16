#include <stdio.h>
#include <limits.h>

int main() {
    int n; // Number of elements in the arrays a and b
    scanf("%d", &n); // Read the first integer n
    int a[n]; // Create an integer array a with a length of n
    int b[n]; // Create an integer array b with a length of n
    int temp = 0; // Initialize a variable temp to 0
    int q = 0; // Initialize a variable q to 0
    int w = INT_MIN; // Initialize a variable w to the smallest possible integer value
    int e = INT_MIN; // Initialize a variable e to the smallest possible integer value
    int f = 0; // Initialize a boolean variable f to false (0)

    for (int i = 0; i < n; i++) { // Start a for loop that iterates through the elements of arrays a and b
        scanf("%d", &a[i]); // Read the next integer value for a[i]
        scanf("%d", &b[i]); // Read the next integer value for b[i]

        if (temp < a[i]) { // If the current value of temp is less than a[i]
            if (q > b[i]) { // Check if the condition q > b[i] is satisfied
                f = 1; // If it is, set f to true (1)
            }
            q = b[i]; // Update q with the new value of b[i]
            temp = a[i]; // Update temp with the new value of a[i]
        }

        if (temp > a[i]) { // If the current value of temp is greater than a[i]
            if (q < b[i]) { // Check if the condition q < b[i] is satisfied
                f = 1; // If it is, set f to true (1)
            }
            q = b[i]; // Update q with the new value of b[i]
            temp = a[i]; // Update temp with the new value of a[i]
        }

        if (a[i] > w) { // If the current value of a[i] is greater than w
            w = a[i]; // Update w with the new value of a[i]
            if (b[i] < e) { // Check if the condition b[i] < e is satisfied
                f = 1; // If it is, set f to true (1)
            }
        }

        if (a[i] < w) { // If the current value of a[i] is less than w
            if (b[i] > e) { // Check if the condition b[i] > e is satisfied
                f = 1; // If it is, set f to true (1)
            }
        }
    }

    if (f == 1) { // After the loop finishes, check the value of the boolean variable f
        printf("Happy Alex\n"); // If it is true, print the message "Happy Alex"
    } else {
        printf("Poor Alex\n"); // Otherwise, print the message "Poor Alex"
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
