#include <stdio.h>  // Importing the standard I/O library
#include <stdlib.h> // Importing the standard library for conversion functions

// Function to read an integer from input
int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int main() {
    // Reading three integers and checking if their sum is greater than or equal to the third integer
    if (nextInt() + nextInt() >= nextInt()) {
        printf("Yes\n"); // Printing "Yes" if the condition is true
    } else {
<<<<<<< HEAD
        printf("No\n");  // Printing "No" if the condition is false
=======
        printf("No\n"); // Printing "No" if the condition is false
>>>>>>> 98c87cb78a (data updated)
    }
    
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
