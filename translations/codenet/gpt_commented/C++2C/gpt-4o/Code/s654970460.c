#include <stdio.h>

int main() {
    // Declare an integer variable 'n' for the number of elements,
    // an array 'a' of size 101 to store the elements, and an integer 'i' for iteration.
    int n, a[101], i;

    // Read the number of elements 'n' from the user.
    scanf("%d", &n);

    // Loop to read 'n' elements into the array 'a'.
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Output the last element of the array (a[n-1]).
    printf("%d", a[n-1]);

    // Loop to output the elements of the array in reverse order,
    // starting from the second last element down to the first element.
    for(i = 1; i < n; i++)
        printf(" %d", a[n - i - 1]);

    // Print a newline character at the end of the output.
    printf("\n");

    // Return 0 to indicate successful completion of the program.
    return 0;
}

// <END-OF-CODE>
