#include <stdio.h> // Including standard input/output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() {
    int n, k; // Declaring variables for the size of the array and number of queries
    scanf("%d %d", &n, &k); // Reading the first two integers 'n' and 'k' from the user

    int *arr = (int *)malloc(n * sizeof(int)); // Dynamically allocating memory for the array 'arr'

    // Initializing the array 'arr' with user input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Reading an integer value from the user and storing it in the array at index 'i'
    }

    int o = 0, e = 0; // Initializing two integer variables 'o' and 'e' to 0

    // Counting the number of 1's and 0's in the array 'arr'
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            o++; // Incrementing the variable 'o' when the current element in the array is 1
        } else {
            e++; // Incrementing the variable 'e' when the current element in the array is 0
        }
    }

    // Processing the user queries
    for (int i = 0; i < k; i++) {
        int l, r; // Declaring variables for the left and right indices of the query
        scanf("%d %d", &l, &r); // Reading the left index 'l' and right index 'r' of the query from the user

        if ((r - l + 1) % 2 == 1) { // Checking if the length of the query is odd
            printf("0\n"); // If the length is odd, printing '0' followed by a newline character
        } else { // If the length is even
            if ((r - l + 1) / 2 <= o) { // Checking if half of the length is less than or equal to the number of 1's in the array
                printf("1\n"); // If it is, printing '1' followed by a newline character
            } else { // Otherwise
                printf("0\n"); // Printing '0' followed by a newline character
            }
        }
    }

    free(arr); // Freeing the dynamically allocated memory for the array
    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
