package main  // Step 1: Declare the main package.

import "fmt"  // Step 2: Import the fmt package for formatted I/O.

func main() {  // Step 3: Define the main function.
    var A, B, C, D, E, max int  // Step 4: Declare integer variables A, B, C, D, E, and max.

    fmt.Scanf("%d %d", &A, &B)  // Step 5: Read two integers A and B from the user.

    C = A + B  // Step 6: Calculate the sum of A and B, store it in C.
    D = A - B  // Step 7: Calculate the difference between A and B, store it in D.
    E = A * B  // Step 8: Calculate the product of A and B, store it in E.

    max = C  // Step 9: Initialize max with the value of C.

    if max < D {  // Step 10: Compare max with D and update max if D is greater.
        max = D
    }
    if max < E {  // Step 11: Compare max with E and update max if E is greater.
        max = E
    }

    fmt.Println(max)  // Step 12: Print the maximum value.
}  // Step 13: End of the main function.

