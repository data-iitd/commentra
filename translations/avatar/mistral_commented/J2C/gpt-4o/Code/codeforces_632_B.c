#include <stdio.h> // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation

int main() { // Starting point of the program
    int n; // Variable to store the number of elements in the array
    scanf("%d", &n); // Reading the number of elements in the array from standard input

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocating an integer array of size n

    for (int i = 0; i < n; i++) { // Iterating through the array to read its elements from standard input
        scanf("%d", &a[i]);
    }

    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s); // Reading the string from standard input
    long sum = 0; // Initializing the sum variable to zero

    for (int i = 0; s[i] != '\0'; i++) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        if (s[i] == 'B') sum += a[i];
    }

    long ans = sum; // Initializing the answer variable with the sum calculated above
    long sum1 = sum; // Initializing a temporary sum variable with the sum calculated above

    for (int i = 0; s[i] != '\0'; i++) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        if (sum1 > ans) ans = sum1; // Update ans if sum1 is greater
    }

    sum1 = sum; // Resetting the temporary sum variable with the sum calculated at the beginning

    for (int i = 0; s[i] != '\0'; i++); // Finding the length of the string
    int length = i; // Storing the length of the string

    for (int i = length - 1; i >= 0; i--) { // Iterating through the string in reverse order
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        if (sum1 > ans) ans = sum1; // Update ans if sum1 is greater
    }

    printf("%ld\n", ans); // Printing the maximum sum found

    free(a); // Freeing the dynamically allocated memory
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
