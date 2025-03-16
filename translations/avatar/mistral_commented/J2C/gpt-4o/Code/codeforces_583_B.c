#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() { // Main function to start the program
    int n; // Variable to store the number of elements in the arrays
    while (scanf("%d", &n) != EOF) { // Reading input until the end of the file is reached
        int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocating an integer array 'a' of size 'n'
        int *b = (int *)malloc(n * sizeof(int)); // Dynamically allocating an integer array 'b' of size 'n'
        int s = -1; // Initializing the variable 's' to -1
        for (int i = 0; i < n; i++) { // Loop to read and initialize the arrays 'a' and 'b'
            scanf("%d", &a[i]); // Reading an integer value and storing it in the 'i'th position of array 'a'
            b[i] = 0; // Initializing all elements of array 'b' to zero
        }
        int tem = 1; // Initializing the variable 'tem' to 1
        int q = 0; // Initializing the variable 'q' to 0
        while (q != n) { // Main loop to find the sequence length
            s++; // Incrementing the variable 's'
            if (tem == 1) { // If 'tem' is 1, perform the first half of the loop
                for (int i = 0; i < n; i++) {
                    if (a[i] <= q && b[i] == 0) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                        b[i] = 1; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                    }
                }
                tem = 0; // Switching the value of 'tem' to 0
            } else { // If 'tem' is 0, perform the second half of the loop
                for (int i = n - 1; i >= 0; i--) {
                    if (a[i] <= q && b[i] == 0) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                        b[i] = 1; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                    }
                }
                tem = 1; // Switching the value of 'tem' to 1
            }
        }
        printf("%d\n", s); // Printing the length of the sequence found
        free(a); // Freeing the allocated memory for array 'a'
        free(b); // Freeing the allocated memory for array 'b'
    }
    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
