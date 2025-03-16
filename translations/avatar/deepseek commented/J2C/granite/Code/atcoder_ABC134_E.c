
#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for dynamic memory allocation
#include <limits.h> // Including the limits header file for INT_MIN and INT_MAX

int main() {
    int n; // Declaring an integer variable n to store the number of elements
    scanf("%d", &n); // Reading the integer n from the input using scanf

    int *arr = (int *)malloc(n * sizeof(int)); // Allocating memory for an array of size n
    if (arr == NULL) { // Checking if memory allocation was successful
        printf("Memory allocation failed"); // Printing an error message if memory allocation failed
        return 1; // Returning 1 to indicate an error
    }

    int *freq = (int *)malloc(n * sizeof(int)); // Allocating memory for an array of size n to store frequencies
    if (freq == NULL) { // Checking if memory allocation was successful
        printf("Memory allocation failed"); // Printing an error message if memory allocation failed
        free(arr); // Freeing the memory allocated for arr
        return 1; // Returning 1 to indicate an error
    }

    for (int i = 0; i < n; i++) { // Looping n times to read n integers
        scanf("%d", &arr[i]); // Reading the next integer from the input using scanf
        freq[i] = 0; // Initializing the frequency of each element to 0
    }

    for (int i = 0; i < n; i++) { // Looping n times to find the frequency of each element
        int key = arr[i]; // Storing the current element in a variable
        int j = i - 1; // Initializing a variable j to store the index of the previous element
        while (j >= 0 && arr[j] > key) { // Looping until the start of the array or until the previous element is less than the current element
            freq[i] += freq[j]; // Incrementing the frequency of the current element by the frequency of the previous element
            j--; // Decrementing j to move to the previous element
        }
    }

    int ans = 0; // Declaring an integer variable ans to store the sum of frequencies
    for (int i = 0; i < n; i++) { // Looping n times to calculate the sum of frequencies
        ans += freq[i] + 1; // Incrementing the sum of frequencies by the frequency of the current element plus 1
    }

    printf("%d", ans); // Printing the sum of frequencies

    free(arr); // Freeing the memory allocated for arr
    free(freq); // Freeing the memory allocated for freq

    return 0; // Returning 0 to indicate successful execution
}
