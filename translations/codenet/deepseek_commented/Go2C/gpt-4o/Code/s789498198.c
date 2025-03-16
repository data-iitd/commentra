#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

<<<<<<< HEAD
// Function to read integers from standard input
=======
// Function to read two integers A and B from standard input
>>>>>>> 98c87cb78a (data updated)
void readInts(int *A, int *B) {
    scanf("%d %d", A, B);
}

// Main function of the program
int main() {
    int A, B;
<<<<<<< HEAD
    // Read two integers A and B from standard input
=======
    // Read two integers A and B
>>>>>>> 98c87cb78a (data updated)
    readInts(&A, &B);

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average of A and B
        printf("%d\n", (A + B) / 2);
    } else {
        // If not even, print "IMPOSSIBLE"
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

/* <END-OF-CODE> */
