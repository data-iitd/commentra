#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Include necessary header files

int main()
{
    int X,A,B,C; // Declare variables X, A, B, C of type int
    int i=0, j=0, k=0; // Initialize variables i, j, k to zero
    int kosu=0; // Initialize variable kosu to zero

    // Input values for A, B, C, and X from the user
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &X);

    // Divide X by 50 and assign the quotient to X
    X = X / 50;

    // Three nested for loops to check if X can be represented as 10*i + 2*j + k
    for(i=0;i<=A;i++){ // Loop through all possible values of i from 0 to A
        for(j=0;j<=B;j++){ // Loop through all possible values of j from 0 to B
            for(k=0;k<=C;k++){ // Loop through all possible values of k from 0 to C
                if(X == (10*i) + (2*j) + k){ // Check if X equals the sum of 10*i, 2*j, and k
                    kosu++; // If so, increment the counter kosu
                }
            }
        }
    }

    // Print the result, which is the number of ways X can be represented as 10*i + 2*j + k
    printf("%d\n",kosu);

    return 0; // Indicate successful termination of the program
}
