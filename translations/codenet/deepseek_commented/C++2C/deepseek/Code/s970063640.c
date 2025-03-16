#include <stdio.h>  // Include the input-output stream library for input and output operations
#include <stdlib.h> // Include the standard library for general utilities

int compare(const void *a, const void *b) { // Define a comparison function for qsort
    return (*(int*)a - *(int*)b); // Return the difference between the two integers
}

int main(){
    int n; // Declare an integer variable to store the number of elements
    scanf("%d", &n); // Read the value of n from the standard input
    int a; // Declare an integer variable to store the value of a
    scanf("%d", &a); // Read the value of a from the standard input
    int sum = 0; // Initialize a variable to store the sum of the last 'a' elements
    int *s = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array 's'
    for(int i = 0; i < n; i++){ // Loop to read 'n' elements into the array 's'
        scanf("%d", &s[i]); // Read the elements from the standard input
    }
    qsort(s, n, sizeof(int), compare); // Sort the array 's' in ascending order using qsort
    for(int i = n - 1; i > n - a - 1; i--){ // Loop to calculate the sum of the last 'a' elements
        sum += s[i]; // Add the value of the current element to the sum
    }
    printf("%d\n", sum); // Print the calculated sum to the standard output
    free(s); // Free the dynamically allocated memory
    return 0; // Return 0 to indicate successful execution
}
