#include <stdio.h> // Including standard I/O library
#include <stdlib.h> // Including standard library for memory allocation
#include <string.h> // Including string library for string manipulation

#define MAX_SIZE 1001 // Defining the maximum size for the array

int main() {
    int n; // Variable to store the number of elements
    scanf("%d", &n); // Reading the number of elements

    int array[MAX_SIZE] = {0}; // Initializing an array to count occurrences

    for (int i = 0; i < n; i++) { // Looping through each element
        int index; // Variable to store the current element
        scanf("%d", &index); // Reading the current element
        array[index]++; // Incrementing the count of the current element
    }

    int countMax = -1; // Initializing the maximum count to -1
    for (int i = 1; i < MAX_SIZE; i++) { // Looping through the array to find the maximum count
        if (countMax < array[i]) {
            countMax = array[i]; // Updating the maximum count if necessary
        }
    }

    if (n % 2 == 0) { // Checking if n is even
        if (countMax <= n / 2) { // Checking if the maximum count is less than or equal to half of n
            printf("YES\n"); // Printing "YES" if the condition is met
        } else {
            printf("NO\n"); // Printing "NO" if the condition is not met
        }
    } else { // If n is odd
        if (countMax <= n / 2 + 1) { // Checking if the maximum count is less than or equal to half of n rounded up
            printf("YES\n"); // Printing "YES" if the condition is met
        } else {
            printf("NO\n"); // Printing "NO" if the condition is not met
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
