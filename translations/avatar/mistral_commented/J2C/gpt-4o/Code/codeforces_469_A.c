#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() { // Starting point of the program
    int n, levels; // Declaring variables for n and levels
    scanf("%d", &n); // Reading the first integer input 'n'
    scanf("%d", &levels); // Reading the second integer input 'levels'

    int sum = 0; // Initializing sum variable to 0
    int sum2 = 0; // Initializing sum2 variable to 0
    int sum3 = 0; // Initializing sum3 variable to 0
    int *arr = (int *)malloc(levels * sizeof(int)); // Creating an integer array 'arr' of size 'levels'
    int count = 0; // Initializing count variable to 0

    for (int i = 0; i < levels; i++) { // Loop to read 'levels' number of integers and store them in 'arr'
        scanf("%d", &arr[i]);
    }

    int level2; // Declaring variable for level2
    scanf("%d", &level2); // Reading the third integer input 'level2'
    int level3 = levels + level2; // Calculating the size of 'arr2'
    int *arr2 = (int *)malloc(level3 * sizeof(int)); // Creating an integer array 'arr2' of size 'level3'

    for (int i = 0; i < levels; i++) { // Loop to copy elements of 'arr' to 'arr2'
        arr2[i] = arr[i];
    }

    for (int i = levels; i < level3; i++) { // Loop to read 'level2' number of integers and store them in 'arr2'
        scanf("%d", &arr2[i]);
    }

    int *arr3 = (int *)malloc(n * sizeof(int)); // Creating an integer array 'arr3' of size 'n'
    for (int i = 0; i < n; i++) { // Loop to initialize 'arr3' with numbers from 1 to 'n'
        arr3[i] = i + 1;
    }

    for (int i = 0; i < n; i++) { // Outer loop to compare each element of 'arr3' with 'arr2'
        for (int x = 0; x < level3; x++) { // Inner loop to find a match between 'arr3[i]' and 'arr2[x]'
            if (arr3[i] == arr2[x]) { // If a match is found
                count++; // Increment the count variable
                break; // Exit the inner loop
            }
        }
    }

    if (count == n) { // If all elements of 'arr3' are present in 'arr2'
        printf("I become the guy.\n"); // Print the message
    } else { // Otherwise
        printf("Oh, my keyboard!\n"); // Print the error message
    }

    // Freeing allocated memory
    free(arr);
    free(arr2);
    free(arr3);

    return 0; // Return statement
}

// <END-OF-CODE>
