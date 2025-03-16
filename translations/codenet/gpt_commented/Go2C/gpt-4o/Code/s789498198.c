#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>
#include <math.h>
=======
#include <math.h>
#include <string.h>
>>>>>>> 98c87cb78a (data updated)

int main() {
    int A, B;
    
    // Read two integers from input
<<<<<<< HEAD
    scanf("%d %d", &A, &B);
=======
    if (scanf("%d %d", &A, &B) != 2) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
>>>>>>> 98c87cb78a (data updated)

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average
        printf("%d\n", (A + B) / 2);
    } else {
        // If odd, print "IMPOSSIBLE"
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

<<<<<<< HEAD
// Utility functions and structures can be added here if needed

// <END-OF-CODE>
=======
/* <END-OF-CODE> */
>>>>>>> 98c87cb78a (data updated)
