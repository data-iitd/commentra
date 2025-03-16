#include <stdio.h>

int main()
{
    // Declare two integer variables A and B to store user input
    int A, B;
    
    // Read two integers from the standard input (scanf) and store them in A and B
    scanf("%d %d", &A, &B);
    
    // Check if A is between 6 and 12 (inclusive)
    if (A < 13 && A >= 6) {
        // If true, calculate B/2 and print the result
        printf("%d\n", B / 2);
    }
    
    // Check if A is less than 6
    if (A < 6) {
        // If true, print 0
        printf("0\n");
    }
    
    // Check if A is 13 or more
    if (A >= 13) {
        // If true, print the value of B
        printf("%d\n", B);        
    }
<<<<<<< HEAD
    
    return 0;
=======
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
