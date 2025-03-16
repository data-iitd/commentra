#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n); // Reading the first integer from the standard input stream and assigning it to the variable n
    int *a = (int *)malloc(n * sizeof(int)); // Creating an integer array of size n
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); // Setting all elements of the array a to the integers read from the standard input stream
    }

    int m = 0; // Initializing the variable m to 0
    for (int i = 1; i < n; ++i) { // Starting a for loop to iterate through the array a from the second element to the last one
        if (fabs(a[m]) < fabs(a[i])) { // Comparing the absolute values of the first and current elements to find the index of the smallest absolute value
            m = i; // Assigning the index of the smallest absolute value to the variable m
        }
    }

    // Array to store the output pairs
    char **r = (char **)malloc(n * n * sizeof(char *));
    int r_size = 0; // To keep track of the number of pairs added

    for (int i = 0; i < n; ++i) { // Starting a for loop to iterate through the array a from the first element to the last one
        if ((a[m] >= 0) ^ (a[i] >= 0)) { // Checking if the signs of the elements at indices m and i are different
            r[r_size] = (char *)malloc(20 * sizeof(char)); // Allocate memory for the string
            sprintf(r[r_size], "%d %d", m + 1, i + 1); // Adding the pair (m+1, i+1) to the array r if the condition is true
            r_size++;
        }
    }

    if (a[m] >= 0) { // Checking if the smallest absolute value is positive
        for (int i = 1; i < n; ++i) { // Starting a for loop to iterate through the array a from the second element to the last one
            r[r_size] = (char *)malloc(20 * sizeof(char)); // Allocate memory for the string
            sprintf(r[r_size], "%d %d", i, i + 1); // Adding the pair (i, i+1) to the array r if the smallest absolute value is positive
            r_size++;
        }
    } else { // If the smallest absolute value is negative
        for (int i = n; i > 1; --i) { // Starting a for loop to iterate through the array a from the last element to the second one
            r[r_size] = (char *)malloc(20 * sizeof(char)); // Allocate memory for the string
            sprintf(r[r_size], "%d %d", i, i - 1); // Adding the pair (i, i-1) to the array r if the smallest absolute value is negative
            r_size++;
        }
    }

    printf("%d\n", r_size); // Printing the size of the array r to the standard output stream
    for (int i = 0; i < r_size; ++i) {
        printf("%s\n", r[i]); // Printing each pair in the array r to the standard output stream
        free(r[i]); // Freeing the allocated memory for each string
    }
    
    free(r); // Freeing the allocated memory for the array of strings
    free(a); // Freeing the allocated memory for the integer array
    return 0;
}

// <END-OF-CODE>
