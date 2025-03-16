

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, temp, q, w, e, f;
    int *a, *b;

    scanf("%d", &n); // Read the number of elements
    a = (int*)malloc(n * sizeof(int)); // Allocate memory for array 'a'
    b = (int*)malloc(n * sizeof(int)); // Allocate memory for array 'b'

    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]); // Read the values for array 'a' and 'b'
    }

    temp = a[0]; // Initialize 'temp' with the first value of 'a'
    q = b[0]; // Initialize 'q' with the first value of 'b'
    w = a[0]; // Initialize 'w' with the first value of 'a'
    e = b[0]; // Initialize 'e' with the first value of 'b'
    f = 0; // Initialize 'f' to 0

    for (i = 1; i < n; i++) {
        if (temp < a[i]) { // Check if the current 'a' value is greater than the stored 'temp' value
            if (q > b[i]) { // Check if the stored 'q' value is greater than the current 'b' value
                f = 1; // Set 'f' to 1 if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (temp > a[i]) { // Check if the current 'a' value is less than the stored 'temp' value
            if (q < b[i]) { // Check if the stored 'q' value is less than the current 'b' value
                f = 1; // Set 'f' to 1 if the condition is met
            }
            q = b[i]; // Update 'q' with the current 'b' value
            temp = a[i]; // Update 'temp' with the current 'a' value
        }
        if (a[i] > w) { // Check if the current 'a' value is greater than the stored 'w' value
            w = a[i]; // Update 'w' with the current 'a' value
            if (b[i] < e) { // Check if the current 'b' value is less than the stored 'e' value
                f = 1; // Set 'f' to 1 if the condition is met
            }
            e = b[i]; // Update 'e' with the current 'b' value
        }
        if (a[i] < w) { // Check if the current 'a' value is less than the stored 'w' value
            if (b[i] > e) { // Check if the current 'b' value is greater than the stored 'e' value
                f = 1; // Set 'f' to 1 if the condition is met
            }
        }
    }

    if (f == 1) {
        printf("Happy Alex"); // Print "Happy Alex" if 'f' is 1
    } else {
        printf("Poor Alex"); // Print "Poor Alex" if 'f' is 0
    }

    free(a); // Free the memory allocated for array 'a'
    free(b); // Free the memory allocated for array 'b'

    return 0;
}

