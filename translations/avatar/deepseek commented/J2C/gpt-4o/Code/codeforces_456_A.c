#include <stdio.h>
#include <stdbool.h>

int main() {
    int n; // Number of elements
    scanf("%d", &n); // Read the number of elements
    int a[n]; // Array 'a' to store first set of values
    int b[n]; // Array 'b' to store second set of values
    int temp = 0; // Variable to temporarily store a value
    int q = 0; // Variable to store a value for comparison
    int w = 0; // Variable to store the maximum value of 'a'
    int e = 0; // Variable to store a value for comparison
    bool f = false; // Boolean variable to determine the output

    // Loop through each element
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]); // Read the values for arrays 'a' and 'b'
        if (temp < a[i]) { // Check if the current 'a' value is greater than the stored 'temp' value
            if (q > b[i]) { // Check if the stored 'q' value is greater than the current 'b' value
                f = true; // Set 'f' to true if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (temp > a[i]) { // Check if the current 'a' value is less than the stored 'temp' value
            if (q < b[i]) { // Check if the stored 'q' value is less than the current 'b' value
                f = true; // Set 'f' to true if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (a[i] > w) { // Check if the current 'a' value is greater than the stored 'w' value
            w = a[i]; // Update 'w' with the current 'a' value
            if (b[i] < e) { // Check if the current 'b' value is less than the stored 'e' value
                f = true; // Set 'f' to true if the condition is met
            }
            e = b[i]; // Update 'e' with the current 'b' value
        }
        if (a[i] < w) { // Check if the current 'a' value is less than the stored 'w' value
            if (b[i] > e) { // Check if the current 'b' value is greater than the stored 'e' value
                f = true; // Set 'f' to true if the condition is met
            }
        }
    }

    // Determine and print the output based on the value of 'f'
    if (f) {
        printf("Happy Alex\n"); // Print "Happy Alex" if 'f' is true
    } else {
        printf("Poor Alex\n"); // Print "Poor Alex" if 'f' is false
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
