#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// Function to find the maximum of two integers.
=======
// Function to calculate the maximum of two integers.
>>>>>>> 98c87cb78a (data updated)
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int H, W, N;
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    // Reads three integers H, W, and N from standard input.
    scanf("%d %d %d", &H, &W, &N);
    
    // Determines the maximum of H and W and assigns it to A.
    int A = max(H, W);
    
    // Calculates the result by dividing N by A and rounding up.
    // This is done by adding N-1 to the division result and then performing integer division by A.
    printf("%d\n", (N + A - 1) / A);
<<<<<<< HEAD

    return 0;
}

// <END-OF-CODE>
=======
    
    return 0;
}

/* <END-OF-CODE> */
>>>>>>> 98c87cb78a (data updated)
