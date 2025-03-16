#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for general functions

int main() { // Defining the main function
    long Q, H, S, D, N; // Declaring variables for prices and quantity

    scanf("%ld", &Q); // Reading the first long value Q from standard input
    scanf("%ld", &H); // Reading the second long value H from standard input
    scanf("%ld", &S); // Reading the third long value S from standard input
    scanf("%ld", &D); // Reading the fourth long value D from standard input
    scanf("%ld", &N); // Reading the fifth long value N from standard input

    long onePrice = (Q * 4 < H * 2 ? (Q * 4 < S ? Q * 4 : S) : (H * 2 < S ? H * 2 : S)); // Calculating the minimum price per item

    if ((double)onePrice <= (double)D / 2) { // Checking if the minimum price per item is less than or equal to half of the deposit amount
        printf("%ld\n", N * onePrice); // If true, printing the result as the product of N and the minimum price per item
    } else { // If false, the following block is executed
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice); // Calculating and printing the result
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
