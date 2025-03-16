// Include the necessary header files for file I/O and string functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main method, which is the entry point of the program
int main() {

    // Declare a variable scn to store the standard input
    FILE *scn = stdin;

    // Declare a variable n to store the size of the array
    int n;

    // Read the first integer n representing the size of the array
    fscanf(scn, "%d", &n);

    // Declare an integer array arr of size n
    int *arr = (int *)malloc(n * sizeof(int));

    // Use a for loop to read n integers from the standard input and store them in the array arr
    for (int i = 0; i < n; i++) {
        fscanf(scn, "%d", &arr[i]); // Read the next integer and store it in the current index of the array
    }

    // Initialize a variable ans with the first element of the array and add 1 to it
    int ans = arr[0] + 1;

    // Use another for loop to iterate through the remaining elements of the array arr
    for (int i = 1; i < n; i++) {
        // Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2;
    }

    // Finally, print the value of ans to the standard output
    printf("%d\n", ans);

    // Free the memory allocated to the array arr
    free(arr);

    // Return 0 to indicate that the program executed successfully
    return 0;
}

