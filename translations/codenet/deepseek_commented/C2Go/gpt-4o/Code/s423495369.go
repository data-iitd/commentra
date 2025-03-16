package main  // Step 1: Declare the main package.

import (  // Step 2: Import the necessary packages.
    "fmt"  // Import the fmt package for formatted I/O.
)

func main() {  // Step 3: Define the main function where the execution of the program begins.
    var A, B, C int  // Step 4: Declare three integer variables A, B, and C.

    fmt.Scanf("%d %d %d", &A, &B, &C)  // Step 5: Use Scanf function to read three integers from the user and store them in variables A, B, and C.

    if (A < C && C < B) || (A > C && C > B) {  // Step 6: Check if the value of C is between A and B.
        fmt.Println("Yes")  // Print "Yes" if the condition is true.
    } else {
        fmt.Println("No")  // Print "No" if the condition is false.
    }
}  // End of the main function.
