<<<<<<< HEAD
#include <stdio.h> // Include the standard input/output library
=======
#include <stdio.h> // Include the standard input-output library
>>>>>>> 98c87cb78a (data updated)

int main() {
    int a; // Declare a variable 'a' of type int to store user input
    scanf("%d", &a); // Read an integer value from standard input and store it in 'a'
    
    // Calculate the expression a + a^2 + a^3 and print the result
    printf("%d\n", a + a*a + a*a*a); 
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
